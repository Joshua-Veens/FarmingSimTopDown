#ifndef FARMHOUSE_HPP
#define FARMHOUSE_HPP

#include "rectangle.hpp"
#include "drawable.hpp"

class farmhouse : public drawable{
private:
    sf::Vector2f position;
    sf::Texture image;
    sf::Sprite sprite;
    sf::FloatRect upper_collider, left_collider, right_collider, lower_left_collider, lower_right_collider, collider_change;
    std::vector<sf::FloatRect> colliders = {upper_collider, left_collider, right_collider, lower_left_collider, lower_right_collider};
public:
    farmhouse(sf::Vector2f position);

    void draw(sf::RenderWindow & window) override;

    std::vector<sf::FloatRect> getColliders() override;

    sf::FloatRect getCollider() override;

};

#endif
