#ifndef FARMHOUSE_HPP
#define FARMHOUSE_HPP

#include "drawable.hpp"
#include "rectangle.hpp"

class farmhouse : public drawable{
private:
    std::string filename = "farmhouse.png";
    sf::Vector2f position;
    sf::Texture image;
    sf::Sprite sprite;
    sf::FloatRect upper_collider, left_collider, right_collider, lower_left_collider, lower_right_collider;
    rectangle upper_rectangle, left_rectangle;
public:
    farmhouse(sf::Vector2f position);

    void draw(sf::RenderWindow & window) override;

};

#endif