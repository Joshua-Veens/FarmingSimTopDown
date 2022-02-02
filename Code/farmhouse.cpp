#include "farmhouse.hpp"

farmhouse::farmhouse(sf::Vector2f position):
        position(position),
        upper_collider(position.x+36, position.y+64, 192, 20),
        left_collider(position.x+36, position.y+84, 20, 165),
        right_collider(position.x+208, position.y+84, 20, 165),
        lower_left_collider(position.x+36, position.y+249, 36, 7),
        lower_right_collider(position.x+192, position.y+249, 36, 7),
        collider_change(position.x+105, position.y+100, 50, 20)

{
    image.loadFromFile("images\\farmhouse.png");
    sprite.setTexture(image);
    sprite.setPosition(position);
}

void farmhouse::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

std::vector<sf::FloatRect> farmhouse::getColliders() {
    return colliders;
}

sf::FloatRect farmhouse::getCollider() {
    return collider_change;
}
