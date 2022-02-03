#include "harvester.hpp"

harvester::harvester(sf::Vector2f position) :
        vehicle(position),
        collider(position.x - 40, position.y - 42, 80, 20),
        auger_collider(position.x - 70, position.y+5, 20, 20)
{
    if(active_size == big){
        image.loadFromFile("harvester\\newholland_closed.png");
    }else{
        image.loadFromFile("harvester\\harvester_closed.png");
    }
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

void harvester::draw(sf::RenderWindow &window) {
    this->updateCollider();
    sprite.setTexture(image, true);
    sprite.setPosition(position);
    if(active_size == big){
        sprite.setOrigin(sf::Vector2f(128,128));
    }else{
        sprite.setOrigin(sf::Vector2f(64,64));
    }
    window.draw(sprite);
}


void harvester::drawWheat(sf::RenderWindow &window, sf::Vector2f position) {
    text_string = std::to_string(wheatCount);
    text = sf::Text(text_string, font);
    text.setCharacterSize(40);
    text.setPosition(sf::Vector2f(position.x+80,position.y+30));
    wheatSprite.setPosition(sf::Vector2f(position.x+10, position.y+20));
    window.draw(wheatSprite);
    window.draw(text);
}

void harvester::drawCorn(sf::RenderWindow &window, sf::Vector2f position) {
    text_string = std::to_string(cornCount);
    text = sf::Text(text_string, font);
    text.setCharacterSize(40);
    text.setPosition(sf::Vector2f(position.x+80,position.y+90));
    cornSprite.setPosition(sf::Vector2f(position.x+10, position.y+80));
    window.draw(cornSprite);
    window.draw(text);
}

void harvester::drawWeed(sf::RenderWindow &window, sf::Vector2f position) {
    text_string = std::to_string(weedCount);
    text = sf::Text(text_string, font);
    text.setCharacterSize(40);
    text.setPosition(sf::Vector2f(position.x+80,position.y+140));
    weedSprite.setPosition(sf::Vector2f(position.x+10, position.y+140));
    window.draw(weedSprite);
    window.draw(text);
}
void harvester::showCropAmount(sf::RenderWindow &window, sf::Vector2f position) {
    drawWheat(window, position);
    drawCorn(window, position);
    drawWeed(window, position);
}


void harvester::addWheat() {
    wheatCount += rand() % ((40 - 30) + 1) + 30;
}

void harvester::addCorn() {
    cornCount += rand() % ((60 - 40) + 1) + 40;
}

void harvester::addWeed() {
    weedCount += rand() % ((10 - 7) + 1) + 7;
}

void harvester::move(sf::Vector2f delta, std::vector<drawable *> objects) {
    for(unsigned int i = 0; i < objects[0]->getColliders().size(); i++){
        if(objects[0]->getColliders()[i].intersects(collider)){
            return;
        }
    }
    for(unsigned int i = 1; i < objects.size(); i++){
        if(objects[i]->getCollider().intersects(collider)){
            return;
        }
    }
    if(active_vehicle == 0){
        position += sf::Vector2f(delta.x/2, delta.y/2);
    }else if(active_vehicle == 1){
        position += sf::Vector2f(delta.x, delta.y);
    }else if(active_vehicle == 2){
        position += sf::Vector2f(delta.x/2, delta.y/2);
    }
}


void harvester::checkIfFull() {
    if(active_size == big){
        if (wheatCount + cornCount + weedCount >= 20000){
            changeToFull();
        }
    }else{
        if (wheatCount + cornCount + weedCount >= 10000){
            changeToFull();
        }
    }
}

void harvester::update(std::vector<std::vector<dirt *>> farmlands){
    checkIfFull();
    for(auto & farmland : farmlands) {
        for (auto &p: farmland) {
            if (p->getBounds().intersects(collider) && active_vehicle == 0) {
                if (p->harvest()) {
                    if (p->getActiveType() == 0) {
                        addWheat();
                    } else if (p->getActiveType() == 1) {
                        addCorn();
                    } else if (p->getActiveType() == 2) {
                        addWeed();
                    }
                }
            }
        }
    }
}

void harvester::setRotation( int rotation ) {
    sprite.setRotation(rotation);
    savedRotation = rotation;
}


void harvester::changeToNormal(){
    if(wheatCount > 0 || cornCount > 0 || weedCount > 0){
        return;
    }
    if(active_size == big){
        image.loadFromFile("harvester\\newholland_closed.png");
    }else{
        image.loadFromFile("harvester\\harvester_closed.png");
    }
    active_vehicle = notHarvesting;
}

void harvester::changeToAction(){
    if(active_size == big){
        image.loadFromFile("harvester\\newhollandharvest.png");
    }else{
        image.loadFromFile("harvester\\harvester.png");
    }
    active_vehicle = harvesting;
}

void harvester::changeToTrailer() {
    if(active_size == big){
        image.loadFromFile("harvester\\newhollandempty.png");
    }else{
        image.loadFromFile("harvester\\harvester_empty.png");
    }
    active_vehicle = overload;
}

void harvester::changeToFull() {
    if(active_size == big){
        image.loadFromFile("harvester\\newhollandempty.png");
    }else{
        image.loadFromFile("harvester\\harvester_empty.png");
    }
    active_vehicle = overload;
}

void harvester::updateCollider(){
    if(savedRotation == 0){
        if(active_size == big){
            collider.left = position.x - 60;
            collider.top = position.y - 47;
            collider.height = 20;
            collider.width = 120;

            auger_collider.left = position.x - 90;
            auger_collider.top = position.y - 10;
            auger_collider.height = 20;
            auger_collider.width = 20;
        }else{
            collider.left = position.x - 40;
            collider.top = position.y - 42;
            collider.height = 20;
            collider.width = 80;

            auger_collider.left = position.x - 70;
            auger_collider.top = position.y + 5;
            auger_collider.height = 20;
            auger_collider.width = 20;
        }

    }
    else if(savedRotation == 180){
        if(active_size == big){
            collider.left = position.x - 60;
            collider.top = position.y + 27;
            collider.height = 20;
            collider.width = 120;

            auger_collider.left = position.x + 72;
            auger_collider.top = position.y - 10;
            auger_collider.height = 20;
            auger_collider.width = 20;
        }else{
            collider.left = position.x - 40;
            collider.top = position.y + 22;
            collider.height = 20;
            collider.width = 80;

            auger_collider.left = position.x + 52;
            auger_collider.top = position.y - 25;
            auger_collider.height = 20;
            auger_collider.width = 20;
        }
    }
    else if(savedRotation == 270){
        if(active_size == big){
            collider.left = position.x - 47;
            collider.top = position.y - 60;
            collider.height = 120;
            collider.width = 20;

            auger_collider.left = position.x - 10;
            auger_collider.top = position.y + 70;
            auger_collider.height = 20;
            auger_collider.width = 20;
        }else{
            collider.left = position.x - 42;
            collider.top = position.y - 40;
            collider.height = 80;
            collider.width = 20;

            auger_collider.left = position.x + 5;
            auger_collider.top = position.y + 50;
            auger_collider.height = 20;
            auger_collider.width = 20;
        }
    }
    else if(savedRotation == 90){
        if(active_size == big){
            collider.left = position.x + 27;
            collider.top = position.y - 60;
            collider.height = 120;
            collider.width = 20;

            auger_collider.left = position.x - 10;
            auger_collider.top = position.y - 90;
            auger_collider.height = 20;
            auger_collider.width = 20;
        }else{
            collider.left = position.x + 22;
            collider.top = position.y - 40;
            collider.height = 80;
            collider.width = 20;

            auger_collider.left = position.x - 25;
            auger_collider.top = position.y - 70;
            auger_collider.height = 20;
            auger_collider.width = 20;
        }
    }
}

int harvester::getRotation() {
    return savedRotation;
}

sf::Vector2f harvester::getPosition() {
    return position;
}

sf::FloatRect harvester::getCollider() {
    return collider;
}

sf::FloatRect harvester::getAugerCollider() {
    return auger_collider;
}

int harvester::getActiveType() {
    return active_vehicle;
}

int harvester::getWheat() {
    return wheatCount;
}

int harvester::getCorn() {
    return cornCount;
}

int harvester::getWeed() {
    return weedCount;
}

void harvester::setWheatCount(unsigned int wheat) {
    wheatCount = wheat;
}

void harvester::setCornCount(unsigned int corn) {
    cornCount = corn;
}

void harvester::setWeedCount(unsigned int weed) {
    weedCount = weed;
}

int harvester::getSize() {
    return active_size;
}

void harvester::setSize(bool size) {
    if(size){
        active_size = big;
        image.loadFromFile("harvester\\newholland_closed.png");
    }else{
        active_size = small;
        image.loadFromFile("harvester\\harvester_closed.png");
    }
    active_vehicle = notHarvesting;
}
