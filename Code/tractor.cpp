//
// Created by joshu on 20-1-2022.
//

#include "tractor.hpp"

tractor::tractor( sf::Vector2f position, std::string type):
        position(position),
        type(type),
        collider(position.x-30, position.y+30, 60, 20),
        blokje(sf::Vector2f(position.x-30,position.y+30), sf::Vector2f(60, 20))
{}

void tractor::draw(sf::RenderWindow &window) {
    image.loadFromFile(filename);
    sprite.setTexture(image);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2f(64,64));
    window.draw(sprite);
    blokje.draw(window);
}

void tractor::move(sf::Vector2f delta) {
    if(type == "seeder"){
        position += sf::Vector2f(delta.x/2, delta.y/2);
    }else if(type == "trekker"){
        position += sf::Vector2f(delta.x*2, delta.y*2);
    }
    this->updateCollider();
}

void tractor::setRotation( int rotation ) {
    sprite.setRotation(rotation);
    savedRotation = rotation;
}

int tractor::getRotation() {
    return savedRotation;
}

sf::Vector2f tractor::getPosition() {
    return position;
}

void tractor::changeToTractor(){
    filename = "trekkerjurgen.png";
    type = "trekker";
}

void tractor::changeToSeeder(){
    filename = "trekkerseeder.png";
    type = "seeder";
}

void tractor::updateCollider(){
    if(savedRotation == 0){
        collider.left = position.x - 30;
        collider.top = position.y + 30;
        blokje.jump(sf::Vector2f(position.x-30, position.y+30));
    }
    else if(savedRotation == 180){
        collider.left = position.x - 30;
        collider.top = position.y - 50;
        blokje.jump(sf::Vector2f(position.x-30, position.y-50));
    }
    else if(savedRotation == 270){
        collider.left = position.x + 30;
        collider.top = position.y - 30;
        collider.height = 60;
        collider.width = 20;
        blokje.jump(sf::Vector2f(position.x+30, position.y-30));
        blokje.setSize(sf::Vector2f(20, 60));
    }
    else if(savedRotation == 90){
        collider.left = position.x - 50;
        collider.top = position.y - 30;
        collider.height = 60;
        collider.width = 20;
        blokje.jump(sf::Vector2f(position.x-50, position.y-30));
        blokje.setSize(sf::Vector2f(20, 60));
    }
}

