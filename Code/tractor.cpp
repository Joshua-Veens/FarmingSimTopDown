//
// Created by joshu on 20-1-2022.
//

#include "tractor.hpp"

tractor::tractor( std::string filename, sf::Vector2f position, std::string type):
        filename(filename),
        position(position),
        type(type)
{}

tractor::tractor() {}

void tractor::draw(sf::RenderWindow &window) {
    image.loadFromFile(filename);
    sprite.setTexture(image);
    sprite.setPosition(position);
    if(type == "trekker"){
        sprite.setOrigin(sf::Vector2f(64,64));
    }
    window.draw(sprite);
}

void tractor::move(sf::Vector2f delta) {
    position += delta;
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