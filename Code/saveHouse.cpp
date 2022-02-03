#include "saveHouse.hpp"

saveHouse::saveHouse(sf::Vector2f position):
    position(position),
    save_collider(position.x - 25, position.y+255, 300, 120),
    house_collider(position.x+13, position.y+115, 235, 133)
{
    image.loadFromFile("images\\saveHouse.png");
    sprite.setTexture(image);
    sprite.setPosition(position);
}

void saveHouse::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

sf::FloatRect saveHouse::getCollider() {
    return house_collider;
}

sf::FloatRect saveHouse::getSavePoint() {
    return save_collider;
}
