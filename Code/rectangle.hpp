#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class rectangle: public drawable {
private:
    sf::RectangleShape square;

public:
    rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::White);

    void draw(sf::RenderWindow & window) const;

    void move(sf::Vector2f delta);

    void jump(sf::Vector2f placement);

    sf::FloatRect getBounds();

    void setSize(sf::Vector2f size);
};

#endif