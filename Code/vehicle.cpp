//
// Created by joshu on 20-1-2022.
//

#include "vehicle.hpp"


void vehicle::setRotation( int rotation ) {
    sprite.setRotation(rotation);
    savedRotation = rotation;
}


int vehicle::getRotation() {
    return savedRotation;
}

sf::Vector2f vehicle::getPosition() {
    return position;
}

void vehicle::setPosition(sf::Vector2f location){
    position = location;
}

