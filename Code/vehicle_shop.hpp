#ifndef VEHICLE_SHOP_HPP
#define VEHICLE_SHOP_HPP

#include "drawable.hpp"
#include "tractor.hpp"
#include "marketplace.hpp"

///@file this file contains the class that creates the object vehicle_shop
///@details vehicle_shop class draws the vehicle shop with corresponding colliders
class vehicle_shop : public drawable
{
private:
    sf::Texture image;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Clock &clock;
    sf::FloatRect collider;
    sf::FloatRect big_tractor, small_tractor;
    sf::FloatRect big_harvester, small_harvester;
    sf::FloatRect shop_collider;
    std::string text_string;
    sf::Font font;
    sf::Color color = sf::Color::White;
    sf::Text text;
    sf::Text moneyText;
    bool boughtBigTractor = false;
    bool boughtBigHarvester = false;
    bool enoughMoney = true;

    void drawTractorPrice(sf::RenderWindow &window);

    void drawHarvesterPrice(sf::RenderWindow &window);

    void drawNotEnoughMoney(sf::RenderWindow &window);
public:
    ///@brief vehicle_shop class constructor
    vehicle_shop(sf::Vector2f position, sf::Clock &clock);

    ///@brief draws the vehicle shop
    void draw(sf::RenderWindow &window) override;

    ///@brief returns the Floatrect of the collider from the building
    sf::FloatRect getCollider() override;

    ///@brief Allows you to buy a vehicle if you have enough money and if the harvester or tractor is in the shop_collider
    void buyVehicle(sf::RenderWindow &window, tractor *trekker, harvester *combine, marketplace *market);

    ///@brief Sets boughtBigTractor bool to true if big tractor has been bought
    void setBigTractor(bool bought);

    ///@brief Sets boughtBigHarvester bool to true if big tractor has been bought
    void setBigHarvester(bool bought);
    ///@brief ostream operator for vehicleShop, prints data about vehicleShop, also useful for saving
    friend std::ostream &operator<<(std::ostream &lhs, vehicle_shop &shop)
    {
        return lhs << " BT: " << shop.boughtBigTractor << " BH: " << shop.boughtBigHarvester;
    }
};

#endif // VEHICLE_SHOP_HPP
