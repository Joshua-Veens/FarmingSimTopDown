#ifndef FARMHOUSE_HPP
#define FARMHOUSE_HPP

#include "tractor.hpp"
#include "rectangle.hpp"

class farmhouse : public drawable{
private:
    std::string filename = "farmhouse.png";
    sf::Vector2f position;
    sf::Texture image;
    sf::Sprite sprite;
    sf::FloatRect upper_collider, left_collider, right_collider, lower_left_collider, lower_right_collider, collider_change;
    rectangle upper_rectangle, left_rectangle, right_rectangle, lower_left_rectangle, lower_right_rectangle, rectangle_change;
    std::vector<sf::FloatRect> colliders = {upper_collider, left_collider, right_collider, lower_left_collider, lower_right_collider};
public:
    farmhouse(sf::Vector2f position);

    void draw(sf::RenderWindow & window) override;

    std::vector<sf::FloatRect> getColliders() override;

    sf::FloatRect getChangeCollider() override;

};

#endif