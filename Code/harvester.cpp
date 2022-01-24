//
// Created by joshu on 24-1-2022.
//

#include "harvester.hpp"

harvester::harvester(sf::Vector2f position, std::string type) :
        position(position),
        type(type),
        collider(position.x - 30, position.y + 30, 60, 20)
//        blokje(sf::Vector2f(position.x-30,position.y+30), sf::Vector2f(60, 20))
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

void harvester::update(std::array<dirt *, 12> farmland){
    for(auto & p : farmland){
        if(p->getBounds().intersects(collider)){
            p->seed();
        }
        p->update();
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
        collider.left = position.x - 30;
        collider.top = position.y + 30;
        collider.height = 20;
        collider.width = 60;
//        blokje.jump(sf::Vector2f(position.x-30, position.y+30));
//        blokje.setSize(sf::Vector2f(60, 20));
    }
    else if(savedRotation == 180){
        collider.left = position.x - 30;
        collider.top = position.y - 50;
        collider.height = 20;
        collider.width = 60;
//        blokje.jump(sf::Vector2f(position.x-30, position.y-50));
//        blokje.setSize(sf::Vector2f(60, 20));
    }
    else if(savedRotation == 270){
        collider.left = position.x + 30;
        collider.top = position.y - 30;
        collider.height = 60;
        collider.width = 20;
//        blokje.jump(sf::Vector2f(position.x+30, position.y-30));
//        blokje.setSize(sf::Vector2f(20, 60));
    }
    else if(savedRotation == 90){
        collider.left = position.x - 50;
        collider.top = position.y - 30;
        collider.height = 60;
        collider.width = 20;
//        blokje.jump(sf::Vector2f(position.x-50, position.y-30));
//        blokje.setSize(sf::Vector2f(20, 60));
    }
}

int harvester::getRotation() {
    return savedRotation;
}

sf::Vector2f harvester::getPosition() {
    return position;
}