//
// Created by joshu on 24-1-2022.
//

#include "harvester.hpp"

harvester::harvester(sf::Vector2f position, std::string type) :
        position(position),
        type(type),
        collider(position.x - 40, position.y - 42, 80, 20)
//        blokje(sf::Vector2f(position.x-40,position.y-42), sf::Vector2f(80, 20))
{}

void harvester::draw(sf::RenderWindow &window) {
    image.loadFromFile(filename);
    sprite.setTexture(image);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2f(64,64));
    window.draw(sprite);
//    blokje.draw(window);
}

void harvester::move(sf::Vector2f delta) {
    if(type == "harvesting"){
        position += sf::Vector2f(delta.x/2, delta.y/2);
    }else if(type == "notHarvesting"){
        position += sf::Vector2f(delta.x, delta.y);
    }
    this->updateCollider();
}

void harvester::update(std::vector<dirt *> farmland){
    for(auto & p : farmland){
        if(p->getBounds().intersects(collider) && type == "harvesting"){
            p->harvest();
        }
    }
}

void harvester::setRotation( int rotation ) {
    sprite.setRotation(rotation);
    savedRotation = rotation;
}

void harvester::changeToNormal(){
    filename = "harvester_closed.png";
    type = "notHarvesting";
}

void harvester::changeToAction(){
    filename = "harvester.png";
    type = "harvesting";
}

void harvester::updateCollider(){
    if(savedRotation == 0){
        collider.left = position.x - 40;
        collider.top = position.y - 42;
        collider.height = 20;
        collider.width = 80;
//        blokje.jump(sf::Vector2f(position.x-40, position.y-42));
//        blokje.setSize(sf::Vector2f(80, 20));
    }
    else if(savedRotation == 180){
        collider.left = position.x - 40;
        collider.top = position.y + 22;
        collider.height = 20;
        collider.width = 80;
//        blokje.jump(sf::Vector2f(position.x-40, position.y+22));
//        blokje.setSize(sf::Vector2f(80, 20));
    }
    else if(savedRotation == 270){
        collider.left = position.x - 42;
        collider.top = position.y - 40;
        collider.height = 80;
        collider.width = 20;
//        blokje.jump(sf::Vector2f(position.x-42, position.y-40));
//        blokje.setSize(sf::Vector2f(20, 80));
    }
    else if(savedRotation == 90){
        collider.left = position.x + 22;
        collider.top = position.y - 40;
        collider.height = 80;
        collider.width = 20;
//        blokje.jump(sf::Vector2f(position.x+22, position.y-40));
//        blokje.setSize(sf::Vector2f(20, 80));
    }
}

int harvester::getRotation() {
    return savedRotation;
}

sf::Vector2f harvester::getPosition() {
    return position;
}