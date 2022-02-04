#include "vehicle.hpp"

vehicle::vehicle(sf::Vector2f position):position(position){}
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

