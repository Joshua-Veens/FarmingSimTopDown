#include "farmhouse.hpp"

farmhouse::farmhouse(sf::Vector2f position):
        position(position),
        upper_collider(position.x+36, position.y+64, 192, 20),
        left_collider(position.x+36, position.y+84, 20, 165),
        right_collider(position.x+208, position.y+84, 20, 165),
        lower_left_collider(position.x+36, position.y+249, 36, 7),
        lower_right_collider(position.x+192, position.y+249, 36, 7),
        collider_change(position.x+105, position.y+100, 50, 20),
        upper_rectangle(sf::Vector2f(position.x+41, position.y+64), sf::Vector2f(182, 10), sf::Color::Blue),
        left_rectangle(sf::Vector2f(position.x+36, position.y+64), sf::Vector2f(5, 185), sf::Color::Yellow),
        right_rectangle(sf::Vector2f(position.x+223, position.y+64), sf::Vector2f(5, 185), sf::Color::Yellow),
        lower_left_rectangle(sf::Vector2f(position.x+36, position.y+249), sf::Vector2f(36, 7), sf::Color::Blue),
        lower_right_rectangle(sf::Vector2f(position.x+192, position.y+249), sf::Vector2f(36, 7), sf::Color::Blue),
        rectangle_change(sf::Vector2f(position.x+105, position.y+100), sf::Vector2f(50, 20), sf::Color::Magenta)
{
    image.loadFromFile("images\\farmhouse.png");
    sprite.setTexture(image);
    sprite.setPosition(position);
}

void farmhouse::draw(sf::RenderWindow &window){
    window.draw(sprite);
    upper_rectangle.draw(window);

    left_rectangle.draw(window);
    right_rectangle.draw(window);

    lower_left_rectangle.draw(window);
    lower_right_rectangle.draw(window);
    rectangle_change.draw(window);
}

std::vector<sf::FloatRect> farmhouse::getColliders() {
    return colliders;
}

sf::FloatRect farmhouse::getCollider() {
    return collider_change;
}