#include "farmhouse.hpp"

farmhouse::farmhouse(sf::Vector2f position):
    position(position),
    upper_rectangle(sf::Vector2f(position.x+64, position.y+92), sf::Vector2f(132, 20), sf::Color::Blue),
    left_rectangle(sf::Vector2f(position.x+64, position.y+112), sf::Vector2f(20, 115), sf::Color::Yellow)
{}

void farmhouse::draw(sf::RenderWindow &window){
    image.loadFromFile(filename);
    sprite.setTexture(image);
    sprite.setPosition(position);
    window.draw(sprite);
    upper_rectangle.draw(window);
    left_rectangle.draw(window);
}