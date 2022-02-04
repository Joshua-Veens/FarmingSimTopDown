#ifndef VEHICLE_SHOP_HPP
#define VEHICLE_SHOP_HPP

#include "drawable.hpp"
#include "tractor.hpp"
#include "marketplace.hpp"

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
    vehicle_shop(sf::Vector2f position, sf::Clock &clock);

    void draw(sf::RenderWindow &window) override;

    sf::FloatRect getCollider() override;

    void buyVehicle(sf::RenderWindow &window, tractor *trekker, harvester *combine, marketplace *market);

    void setBigTractor(bool bought);

    void setBigHarvester(bool bought);
    ///@brief ostream operator for vehicleShop, prints data about vehicleShop, also useful for saving
    friend std::ostream &operator<<(std::ostream &lhs, vehicle_shop &shop)
    {
        return lhs << " BT: " << shop.boughtBigTractor << " BH: " << shop.boughtBigHarvester;
    }
};

#endif // VEHICLE_SHOP_HPP
