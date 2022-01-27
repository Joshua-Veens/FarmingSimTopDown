#include "tree.hpp"

tree::tree(sf::Vector2f position):
    position(position)
{}

void tree::draw(sf::RenderWindow &window) {
    image.loadFromFile(filename);
    sprite.setTexture(image);
    sprite.setPosition(position);
    window.draw(sprite);
}