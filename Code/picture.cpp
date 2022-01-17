#include "picture.hpp"
#include <iostream>

picture::picture( sf::Vector2f position, sf::Texture texture, sf::Sprite sprite):
    position(position),
    texture(texture),
    sprite(sprite)
{}

void picture::draw(sf::RenderWindow &window) {
    texture.loadFromFile("trekkerJurgen.png");
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2f(64,64));
    window.draw(sprite);
}

void picture::move(sf::Vector2f delta) {
    position += delta;
}

void picture::setRotation( int rotation ) {
    sprite.setRotation(rotation);
}