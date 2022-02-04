#ifndef FARMHOUSE_HPP
#define FARMHOUSE_HPP

#include "rectangle.hpp"
#include "drawable.hpp"

/// \brief farmhouse Class
/// \details The farmhouse class makes the farmhouse in the game. It has colliders so you cant drive through it. And it had its one image which will be rendered by the drawables class.

class farmhouse : public drawable{
private:
    sf::Vector2f position;
    sf::Texture image;
    sf::Sprite sprite;
    sf::FloatRect upper_collider, left_collider, right_collider, lower_left_collider, lower_right_collider, collider_change;
    std::vector<sf::FloatRect> colliders = {upper_collider, left_collider, right_collider, lower_left_collider, lower_right_collider};
public:

    /// @brief constructor of the farmhouse object
    farmhouse(sf::Vector2f position);


    /// @brief draws the farmhouse to the screen
    void draw(sf::RenderWindow & window) override;

    /// @brief sends the cords of the collision box of the farmhosue
    std::vector<sf::FloatRect> getColliders() override;


    /// @brief send the collision box of the farmhouse
    sf::FloatRect getCollider() override;

};

#endif
