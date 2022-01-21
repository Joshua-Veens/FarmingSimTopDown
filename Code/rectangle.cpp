#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color):
        square(sf::RectangleShape(size))
    {
        square.setPosition(position);
        square.setFillColor(color);
    }

void rectangle::draw(sf::RenderWindow &window) const {
    window.draw(square);
}

void rectangle::move(sf::Vector2f delta) {
    square.setPosition(square.getPosition()+delta);
}

void rectangle::jump(sf::Vector2f placement) {
    square.setPosition(placement);
}

sf::FloatRect rectangle::getBounds() {
    return square.getGlobalBounds();
}

void rectangle::setSize(sf::Vector2f size){
    square.setSize(size);
}