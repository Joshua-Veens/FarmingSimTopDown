#ifndef VEHICLE_SHOP_HPP
#define VEHICLE_SHOP_HPP

#include "drawable.hpp"
#include "tractor.hpp"
#include "rectangle.hpp"

class vehicle_shop : public drawable{
private:
    sf::Texture image;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::FloatRect collider;
    sf::FloatRect big_tractor, small_tractor;
    sf::FloatRect big_harvester, small_harvester;
    sf::FloatRect shop_collider;
//    rectangle blokje;
public:
    vehicle_shop(sf::Vector2f position);

    void draw(sf::RenderWindow &window) override;

    sf::FloatRect getCollider() override;

    void buyVehicle(sf::RenderWindow & window, tractor * trekker, harvester * combine);

    void drawTractorPrice();
};


#endif //VEHICLE_SHOP_HPP
