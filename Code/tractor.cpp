#include "tractor.hpp"

tractor::tractor( sf::Vector2f position):
        vehicle(position),
        seeder_collider(position.x-30, position.y+30, 60, 20),
        tractor_collider(position.x-10, position.y-36, 20, 5),
        trailer_collider(position.x-20, position.y+55, 40, 70),
        blokje(sf::Vector2f(position.x-20, position.y+55), sf::Vector2f(40, 70))
{
    image.loadFromFile("images\\trekkerjurgen.png");
    wheatImage.loadFromFile("images\\wheatCrop.png");
    cornImage.loadFromFile("images\\cornCrop.png");
}

void tractor::draw(sf::RenderWindow &window) {
    this->updateCollider();
    sprite.setTexture(image, true);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2f(64,64));
    window.draw(sprite);
    blokje.draw(window);
}

void tractor::move(sf::Vector2f delta, std::vector<drawable *> objects) {
    for(unsigned int i = 0; i < objects[0]->getColliders().size(); i++){
        if(objects[0]->getColliders()[i].intersects(tractor_collider)){
            return;
        }
    }
    if(objects[1]->getCollider().intersects(tractor_collider)){
        return;
    }
    if(objects[1]->getSavePoint().intersects(tractor_collider)){
//        SPECIAAL PLEKJE VOOR JUSTIN ZIJN CODE
    }
    if(active_type == 1){
        position += sf::Vector2f(delta.x/1.5, delta.y/1.5);
    }else if(active_type == trekker or active_type == trailer){
        position += sf::Vector2f(delta.x*2, delta.y*2);
    }
}


void tractor::update(std::vector<std::vector<dirt *>> farmlands){
    for(auto & farmland : farmlands) {
        for (auto &p: farmland) {
            if (p->getBounds().intersects(seeder_collider) && active_type == 1) {
                p->seed();
            }
            p->update();
        }
    }
}

void tractor::overloadCrop(harvester *combine) {
    unsigned int total = wheatCount + cornCount;
    if(total == 40000){
        return;
    }
    if(combine->getAugerCollider().intersects(trailer_collider) && combine->getActiveType() == 2 && active_type == trailer){
        if(total + combine->getWheat() > 40000){
            unsigned int wheat = total + combine->getWheat() - 40000;
            wheatCount += combine->getWheat() - wheat;
            combine->setWheatCount(wheat);
            return;
        }else{
            wheatCount += combine->getWheat();
            combine->setWheatCount(0);
        }
        if(total + combine->getCorn() > 40000){
            unsigned int corn = total + combine->getCorn() - 40000;
            cornCount += combine->getCorn() - corn;
            combine->setCornCount(corn);
            return;
        }else{
            cornCount += combine->getCorn();
            combine->setCornCount(0);
        }
    }
}

void tractor::setRotation( int rotation ) {
    sprite.setRotation(rotation);
    savedRotation = rotation;
}

void tractor::changeToNormal(){
    image.loadFromFile("images\\trekkerjurgen.png");
    active_type = trekker;
}

void tractor::changeToAction(){
    image.loadFromFile("images\\trekkerseeder.png");
    active_type = seeder;
}

void tractor::changeToTrailer() {
    image.loadFromFile("images\\aanhanger.png");
    active_type = trailer;
}

void tractor::updateCollider(){
    if(savedRotation == 0){
        seeder_collider.left = position.x - 30;
        seeder_collider.top = position.y + 30;
        seeder_collider.height = 20;
        seeder_collider.width = 60;

        tractor_collider.left = position.x - 10;
        tractor_collider.top = position.y - 36;
        tractor_collider.height = 5;
        tractor_collider.width = 20;

        trailer_collider.left = position.x - 20;
        trailer_collider.top = position.y + 55;
        trailer_collider.height = 70;
        trailer_collider.width = 40;

        blokje.jump(sf::Vector2f(position.x - 20, position.y + 55));
        blokje.setSize(sf::Vector2f(40, 70));
    }
    else if(savedRotation == 180){
        seeder_collider.left = position.x - 30;
        seeder_collider.top = position.y - 50;
        seeder_collider.height = 20;
        seeder_collider.width = 60;

        tractor_collider.left = position.x - 10;
        tractor_collider.top = position.y + 36;
        tractor_collider.height = 5;
        tractor_collider.width = 20;

        trailer_collider.left = position.x - 20;
        trailer_collider.top = position.y - 125;
        trailer_collider.height = 70;
        trailer_collider.width = 40;

        blokje.jump(sf::Vector2f(position.x - 20, position.y - 125));
        blokje.setSize(sf::Vector2f(40, 70));
    }
    else if(savedRotation == 270){
        seeder_collider.left = position.x + 30;
        seeder_collider.top = position.y - 30;
        seeder_collider.height = 60;
        seeder_collider.width = 20;

        tractor_collider.left = position.x - 35;
        tractor_collider.top = position.y - 10;
        tractor_collider.height = 20;
        tractor_collider.width = 5;

        trailer_collider.left = position.x + 55;
        trailer_collider.top = position.y - 20;
        trailer_collider.height = 40;
        trailer_collider.width = 70;

        blokje.jump(sf::Vector2f(position.x + 55, position.y - 20));
        blokje.setSize(sf::Vector2f(70, 40));
    }
    else if(savedRotation == 90){
        seeder_collider.left = position.x - 50;
        seeder_collider.top = position.y - 30;
        seeder_collider.height = 60;
        seeder_collider.width = 20;

        tractor_collider.left = position.x + 32;
        tractor_collider.top = position.y - 10;
        tractor_collider.height = 20;
        tractor_collider.width = 5;

        trailer_collider.left = position.x - 125;
        trailer_collider.top = position.y - 20;
        trailer_collider.height = 40;
        trailer_collider.width = 70;

        blokje.jump(sf::Vector2f(position.x - 125, position.y - 20));
        blokje.setSize(sf::Vector2f(70, 40));
    }
}

int tractor::getRotation() {
    return savedRotation;
}

sf::Vector2f tractor::getPosition() {
    return position;
}

void tractor::setPosition(sf::Vector2f location){
    position = location;
}

sf::FloatRect tractor::getCollider() {
    return tractor_collider;
}

void tractor::setCrop(std::vector<std::vector<dirt *>> farmlands, sf::Clock clock){
    sf::Time time = clock.getElapsedTime();
    clock.restart();
    if (time.asMilliseconds() > 500) {
        for (auto &farmland: farmlands) {
            for (auto &p: farmland) {
                if (p->getState() == dirt::unseeded) {
                    if (this->currentCrop == wheat) {
                        p->changeCrop(corn);
                    } else {
                        p->changeCrop(wheat);
                    }
                }
            }
        }
        if (currentCrop == wheat) {
            currentCrop = corn;
        } else {
            currentCrop = wheat;
        }
    }
}

void tractor::drawWheat(sf::RenderWindow &window) {
    text_string = std::to_string(wheatCount);
    sf::Font font;
    font.loadFromFile(font_file);
    sf::Text text(text_string, font);
    text.setCharacterSize(40);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(color);
    text.setPosition(sf::Vector2f(80,20));
    wheatSprite.setTexture(wheatImage);
    wheatSprite.setPosition(sf::Vector2f(10, 20));
    window.draw(wheatSprite);
    window.draw(text);
}

void tractor::drawCorn(sf::RenderWindow &window) {
    text_string = std::to_string(cornCount);
    sf::Font font;
    font.loadFromFile(font_file);
    sf::Text text(text_string, font);
    text.setCharacterSize(40);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(color);
    text.setPosition(sf::Vector2f(80,80));
    cornSprite.setTexture(cornImage);
    cornSprite.setPosition(sf::Vector2f(10, 80));
    window.draw(cornSprite);
    window.draw(text);
}

void tractor::showCropAmount(sf::RenderWindow &window) {
    drawWheat(window);
    drawCorn(window);
}

int tractor::getActiveType(){
    return active_type;
}
