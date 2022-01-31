#include "harvester.hpp"

harvester::harvester(sf::Vector2f position) :
        vehicle(position),
        collider(position.x - 40, position.y - 42, 80, 20),
        blokje(sf::Vector2f(position.x-40,position.y-42), sf::Vector2f(80, 20))
{image.loadFromFile("images\\harvester_closed.png");}

void harvester::draw(sf::RenderWindow &window) {
    this->updateCollider();
    sprite.setTexture(image);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2f(64,64));
    window.draw(sprite);
    blokje.draw(window);
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
    if(objects[0]->getCollider().intersects(collider)){
        // SPECIAL PLEKJE VOOR ERIKS ZIJN CODE
    }

    if(active_type == 0){
        position += sf::Vector2f(delta.x/2, delta.y/2);
    }else if(active_type == 1){
        position += sf::Vector2f(delta.x, delta.y);
    }else if(active_type == 2){
        position += sf::Vector2f(delta.x/2, delta.y/2);
    }
}

void harvester::checkIfFull(std::vector<dirt *> farmland) {
    inventory = farmland[0]->getWheat();
    inventory = farmland[0]->getCorn();
    if (inventory >= 10000){
        changeToFull();
    }
}

void harvester::update(std::vector<dirt *> farmland){
    checkIfFull(farmland);
    for(auto & p : farmland){
        if(p->getBounds().intersects(collider) && active_type == 0){
            p->harvest();
        }
    }
}

void harvester::setRotation( int rotation ) {
    sprite.setRotation(rotation);
    savedRotation = rotation;
}


void harvester::changeToNormal(){
    image.loadFromFile("images\\harvester_closed.png");
    active_type = notHarvesting;
}

void harvester::changeToAction(){
    image.loadFromFile("images\\harvester.png");
    active_type = harvesting;
}

void harvester::changeToFull() {
    image.loadFromFile("images\\harvester_empty.png");
    active_type = full;
}

void harvester::updateCollider(){
    if(savedRotation == 0){
        collider.left = position.x - 40;
        collider.top = position.y - 42;
        collider.height = 20;
        collider.width = 80;
        blokje.jump(sf::Vector2f(position.x-40, position.y-42));
        blokje.setSize(sf::Vector2f(80, 20));
    }
    else if(savedRotation == 180){
        collider.left = position.x - 40;
        collider.top = position.y + 22;
        collider.height = 20;
        collider.width = 80;
        blokje.jump(sf::Vector2f(position.x-40, position.y+22));
        blokje.setSize(sf::Vector2f(80, 20));
    }
    else if(savedRotation == 270){
        collider.left = position.x - 42;
        collider.top = position.y - 40;
        collider.height = 80;
        collider.width = 20;
        blokje.jump(sf::Vector2f(position.x-42, position.y-40));
        blokje.setSize(sf::Vector2f(20, 80));
    }
    else if(savedRotation == 90){
        collider.left = position.x + 22;
        collider.top = position.y - 40;
        collider.height = 80;
        collider.width = 20;
        blokje.jump(sf::Vector2f(position.x+22, position.y-40));
        blokje.setSize(sf::Vector2f(20, 80));
    }
}

int harvester::getRotation() {
    return savedRotation;
}

sf::Vector2f harvester::getPosition() {
    return position;
}