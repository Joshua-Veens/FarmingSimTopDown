#include "tractor.hpp"
#include "iostream"

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
    weedImage.loadFromFile("images\\weedCrop.png");
    font.loadFromFile("Xhers_Regular.otf");
    text.setStyle(sf::Text::Bold);
    text.setFillColor(color);
    wheatSprite.setTexture(wheatImage);
    cornSprite.setTexture(cornImage);
    weedSprite.setTexture(weedImage);
}

void tractor::draw(sf::RenderWindow &window) {
    this->updateCollider();
    sprite.setTexture(image, true);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2f(64,64));
    window.draw(sprite);
//    blokje.draw(window);
}

void tractor::move(sf::Vector2f delta, std::vector<drawable *> objects) {
    for(unsigned int i = 0; i < objects[0]->getColliders().size(); i++){
        if(objects[0]->getColliders()[i].intersects(tractor_collider)){
            return;
        }
    }
    for(unsigned int i = 1; i < objects.size(); i++){
        if(objects[i]->getCollider().intersects(tractor_collider)){
            return;
        }
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
                if(active_seeds == 0){
                    p->changeToWheat();
                }else if(active_seeds == 1){
                    p->changeToCorn();
                }else if(active_seeds == 2){
                    p->changeToWeed();
                }
            }
            p->update();
        }
    }
}

void tractor::overloadCrop(harvester *combine) {
    unsigned int total = wheatCount + cornCount + weedCount;
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
        if(total + combine->getWeed() > 40000){
            unsigned int weed = total + combine->getWeed() - 40000;
            weedCount += combine->getWeed() - weed;
            combine->setWeedCount(weed);
            return;
        }else{
            weedCount += combine->getWeed();
            combine->setWeedCount(0);
        }
        if(wheatCount + cornCount + weedCount > 0){
            image.loadFromFile("images\\aanhanger_full.png");
        }
    }
}

void tractor::depositCrop(sf::RenderWindow & window, inventory *silo) {
    if(silo->getDepositCollider().intersects(trailer_collider) && active_type == trailer){
        drawUnloadHelp(window, silo);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
            silo->addWheat(wheatCount);
            wheatCount = 0;
            silo->addCorn(cornCount);
            cornCount = 0;
            silo->addWeed(weedCount);
            weedCount = 0;
            image.loadFromFile("images\\aanhanger.png");
        }
        int free_space = 40000 - wheatCount - cornCount - weedCount;
        if(free_space > 0){
            auto mouse_pos = sf::Mouse::getPosition(window);
            auto translated_pos = window.mapPixelToCoords(mouse_pos);
            if(silo->getWheatTextCollider().contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(silo->getWheat() >= free_space){
                    silo->removeWheat(free_space);
                    wheatCount += free_space;
                }else{
                    wheatCount += silo->getWheat();
                    silo->removeWheat(silo->getWheat());
                }
                image.loadFromFile("images\\aanhanger_full.png");
            }
            if(silo->getCornTextCollider().contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(silo->getCorn() >= free_space){
                    silo->removeCorn(free_space);
                    cornCount += free_space;
                }else{
                    cornCount += silo->getCorn();
                    silo->removeCorn(silo->getCorn());
                }
                image.loadFromFile("images\\aanhanger_full.png");
            }
            if(silo->getWeedTextCollider().contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(silo->getWeed() >= free_space){
                    silo->removeWeed(free_space);
                    weedCount += free_space;
                }else{
                    weedCount += silo->getWeed();
                    silo->removeWeed(silo->getWeed());
                }
                image.loadFromFile("images\\aanhanger_full.png");
            }
        }
    }
}

void tractor::sellCrops(sf::RenderWindow & window, marketplace * market) {
    if(market->getSellCollider().intersects(trailer_collider) && active_type == trailer){
        drawSellHelp(window, market);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
            market->sellCrops(wheatCount, cornCount, weedCount);
            wheatCount = 0;
            cornCount = 0;
            weedCount = 0;
            image.loadFromFile("images\\aanhanger.png");
        }
    }
}

void tractor::setRotation( int rotation ) {
    sprite.setRotation(rotation);
    savedRotation = rotation;
}

void tractor::changeToNormal(){
    if(wheatCount > 0 || cornCount > 0 || weedCount > 0){
        return;
    }
    image.loadFromFile("images\\trekkerjurgen.png");
    active_type = trekker;
}

void tractor::changeToAction(){
    if(wheatCount > 0 || cornCount > 0 || weedCount > 0){
        return;
    }
    image.loadFromFile("images\\trekkerseeder.png");
    active_type = seeder;
}

void tractor::changeToTrailer() {
    if(wheatCount > 0 || cornCount > 0 || weedCount > 0){
        image.loadFromFile("images\\aanhanger_full.png");
    }else{
        image.loadFromFile("images\\aanhanger.png");
    }
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

void tractor::setCrop(sf::Clock & clock){
    sf::Time time = clock.getElapsedTime();
    clock.restart();
    if (time.asMilliseconds() > 500)
    {
        if(active_seeds == 0){
            this->active_seeds = cornSeeds;
        }else if(active_seeds == 1){
            this->active_seeds = weedSeeds;
        }else if(active_seeds == 2){
            this->active_seeds = wheatSeeds;
        }
    }
}

void tractor::drawWheat(sf::RenderWindow &window, sf::Vector2f position) {
    text_string = std::to_string(wheatCount);
    text = sf::Text(text_string, font);
    text.setCharacterSize(40);
    text.setPosition(sf::Vector2f(position.x+80,position.y+30));
    wheatSprite.setPosition(sf::Vector2f(position.x+10, position.y+20));
    window.draw(wheatSprite);
    window.draw(text);
}

void tractor::drawCorn(sf::RenderWindow &window, sf::Vector2f position) {
    text_string = std::to_string(cornCount);
    text = sf::Text(text_string, font);
    text.setCharacterSize(40);
    text.setPosition(sf::Vector2f(position.x+80,position.y+90));
    cornSprite.setPosition(sf::Vector2f(position.x+10, position.y+80));
    window.draw(cornSprite);
    window.draw(text);
}

void tractor::drawWeed(sf::RenderWindow &window, sf::Vector2f position) {
    text_string = std::to_string(weedCount);
    text = sf::Text(text_string, font);
    text.setCharacterSize(40);
    text.setPosition(sf::Vector2f(position.x+80,position.y+140));
    weedSprite.setPosition(sf::Vector2f(position.x+10, position.y+140));
    window.draw(weedSprite);
    window.draw(text);
}

void tractor::drawWhatSeeding(sf::RenderWindow &window, sf::Vector2f position) {
    text_string = "Seeds";
    text = sf::Text(text_string, font);
    text.setCharacterSize(40);
    text.setPosition(sf::Vector2f(position.x+92,position.y+24));
    window.draw(text);
    if(active_seeds == 0){
        wheatSprite.setPosition(sf::Vector2f(position.x+20, position.y+20));
        window.draw(wheatSprite);
    }else if(active_seeds == 1){
        cornSprite.setPosition(sf::Vector2f(position.x+20, position.y+20));
        window.draw(cornSprite);
    }else if(active_seeds == 2){
        weedSprite.setPosition(sf::Vector2f(position.x+20, position.y+20));
        window.draw(weedSprite);
    }
}

void tractor::drawUnloadHelp(sf::RenderWindow &window, inventory * silo) {
    text_string = "Press \"I\" to unload";
    text = sf::Text(text_string, font);
    text.setCharacterSize(32);
    text.setPosition(sf::Vector2f (silo->getPosition().x+160, silo->getPosition().y+160));
    window.draw(text);
}

void tractor::drawSellHelp(sf::RenderWindow &window, marketplace * market) {
    text_string = "Press \"I\" to sell all crops";
    text = sf::Text(text_string, font);
    text.setCharacterSize(32);
    text.setPosition(sf::Vector2f(market->getPosition().x+160, market->getPosition().y+160));
    window.draw(text);
}

void tractor::showCropAmount(sf::RenderWindow &window, sf::Vector2f position) {
    drawWheat(window, position);
    drawCorn(window, position);
    drawWeed(window, position);
}

int tractor::getActiveType(){
    return active_type;
}


