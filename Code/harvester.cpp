#include "harvester.hpp"
#include "iostream"

harvester::harvester(sf::Vector2f position) :
        vehicle(position),
        collider(position.x - 40, position.y - 42, 80, 20),
        auger_collider(position.x - 70, position.y+5, 20, 20)
{
    image.loadFromFile("images\\harvester_closed.png");
    wheatImage.loadFromFile("images\\wheatCrop.png");
    cornImage.loadFromFile("images\\cornCrop.png");
}

void harvester::draw(sf::RenderWindow &window) {
    this->updateCollider();
    sprite.setTexture(image, true);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2f(64,64));
    window.draw(sprite);
}

void harvester::drawWheat(sf::RenderWindow &window) {
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

void harvester::drawCorn(sf::RenderWindow &window) {
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

void harvester::showCropAmount(sf::RenderWindow &window) {
    drawWheat(window);
    drawCorn(window);
}


void harvester::addWheat() {
    wheatCount += rand() % ((40 - 30) + 1) + 30;
}

void harvester::addCorn() {
    cornCount += rand() % ((60 - 40) + 1) + 40;
}

void harvester::move(sf::Vector2f delta, std::vector<drawable *> objects) {
    for(unsigned int i = 0; i < objects[0]->getColliders().size(); i++){
        if(objects[0]->getColliders()[i].intersects(collider)){
            return;
        }
    }
    if(objects[1]->getCollider().intersects(collider)){
        return;
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
    if (wheatCount + cornCount >= 10000){
        changeToFull();
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
    if(wheatCount > 0 || cornCount > 0){
        return;
    }
    image.loadFromFile("images\\harvester_closed.png");
    active_vehicle = notHarvesting;
}

void harvester::changeToAction(){
    image.loadFromFile("images\\harvester.png");
    active_vehicle = harvesting;
}

void harvester::changeToTrailer() {
    image.loadFromFile("images\\harvester_empty.png");
    active_vehicle = overload;
}

void harvester::changeToFull() {
    image.loadFromFile("images\\harvester_empty.png");
    active_vehicle = overload;
}

void harvester::updateCollider(){
    if(savedRotation == 0){
        collider.left = position.x - 40;
        collider.top = position.y - 42;
        collider.height = 20;
        collider.width = 80;

        auger_collider.left = position.x - 70;
        auger_collider.top = position.y + 5;
        auger_collider.height = 20;
        auger_collider.width = 20;

    }
    else if(savedRotation == 180){
        collider.left = position.x - 40;
        collider.top = position.y + 22;
        collider.height = 20;
        collider.width = 80;

        auger_collider.left = position.x + 52;
        auger_collider.top = position.y - 25;
        auger_collider.height = 20;
        auger_collider.width = 20;

    }
    else if(savedRotation == 270){
        collider.left = position.x - 42;
        collider.top = position.y - 40;
        collider.height = 80;
        collider.width = 20;

        auger_collider.left = position.x + 5;
        auger_collider.top = position.y + 50;
        auger_collider.height = 20;
        auger_collider.width = 20;

    }
    else if(savedRotation == 90){
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

void harvester::setWheatCount(unsigned int wheat) {
    wheatCount = wheat;
}

void harvester::setCornCount(unsigned int corn) {
    cornCount = corn;
}
