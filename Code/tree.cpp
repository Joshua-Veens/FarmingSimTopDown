#include "tree.hpp"

tree::tree(sf::Vector2f position, int index):
    position(position),
    collider(position.x+55, position.y+102, 15, 25)
{
    image.loadFromFile(files[index]);
    sprite.setTexture(image);
    sprite.setPosition(position);
}

void tree::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

sf::FloatRect tree::getCollider() {
    return collider;
}