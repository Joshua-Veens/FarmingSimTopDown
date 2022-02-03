#include "vehicle_shop.hpp"

vehicle_shop::vehicle_shop(sf::Vector2f position):
    position(position),
    collider(position.x, position.y + 25, 512, 206),
    big_tractor(position.x+10, position.y + 340, 90, 60),
    small_tractor(position.x+410, position.y + 242, 90, 60),
    big_harvester(position.x+230, position.y + 270, 90, 60),
    small_harvester(position.x+410, position.y + 430, 90, 60),
    shop_collider(position.x+210, position.y + 430, 90, 60)
//    blokje(sf::Vector2f(position.x+210, position.y + 430), sf::Vector2f(90, 60))
{
    image.loadFromFile("images\\shop.png");
    sprite.setTexture(image);
    sprite.setPosition(position);
}


void vehicle_shop::draw(sf::RenderWindow &window) {
    window.draw(sprite);
//    blokje.draw(window);
}

sf::FloatRect vehicle_shop::getCollider() {
    return collider;
}


void vehicle_shop::buyVehicle(sf::RenderWindow & window, tractor * trekker, harvester * combine) {
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);
    if(trekker->getCollider().intersects(shop_collider)){
        if(trekker->getSize() == 0){
            if(big_tractor.contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                trekker->setSize(true);
            }
        }else{
            if(small_tractor.contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                trekker->setSize(false);
            }
        }
    }
    if(combine->getCollider().intersects(shop_collider)){

    }
}