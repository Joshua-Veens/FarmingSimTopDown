#include "saveHouse.hpp"

saveHouse::saveHouse(sf::Vector2f position):
    position(position),
    save_collider(position.x+150, position.y+260, 80, 50),
    house_collider(position.x+13, position.y+115, 235, 133),
    blokje(sf::Vector2f(position.x+150, position.y+260), sf::Vector2f(80, 50)),
    huis_blok(sf::Vector2f(position.x+13, position.y+115), sf::Vector2f(235, 133))
{
    image.loadFromFile("images\\saveHouse.png");
    sprite.setTexture(image);
    sprite.setPosition(position);
}

void saveHouse::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    blokje.draw(window);
    huis_blok.draw(window);
}

sf::FloatRect saveHouse::getCollider() {
    return house_collider;
}

sf::FloatRect saveHouse::getSavePoint() {
    return save_collider;
}