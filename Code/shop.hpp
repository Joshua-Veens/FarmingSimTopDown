// this file contains doxygen files
#ifndef V2CPSE2_EXAMPLES_SHOP_HPP
#define V2CPSE2_EXAMPLES_SHOP_HPP

#include "dirt.hpp"
#include "marketplace.hpp"

/// @file shop.hpp
/// @brief shop class
/// @details makes the shop class. It makes it possible to buy farmland.

class shop : public drawable{
private:
    sf::Texture image;
    sf::Sprite sprite;
    std::string text_string;
    sf::Font font;
    sf::Color color = sf::Color::White;
    sf::Text text;
    sf::Text moneyText;
    std::vector<std::vector<dirt *>> & farmlands;
    sf::Clock & clock;
    std::vector<sf::Vector2f> saleSigns;
    std::vector<int> prices = {10000,60000,30000,75000,32000};
    std::vector<sf::FloatRect> colliders;
    marketplace * market;
    bool enoughMoney = true;

    void drawPrice(sf::RenderWindow &window, int price, sf::Vector2f position);

    void drawNotEnoughMoney(sf::RenderWindow &window);

public:
    /// @brief constructor of shop class
    shop(std::vector<std::vector<dirt *>> & farmlands, marketplace * market, sf::Clock & clock);

    /// @brief makes the pillars next to farmlands witch a player is able to buy
    void draw(sf::RenderWindow &window);

    /// @brief draws the pillars
    void addForSaleSign(sf::Vector2f position);

    /// @brief changes the land if bought by a player.
    /// @details first checks if player has enough money to buy the piece of land later removes the amount for the land from the players money
    /// later removes the for sale sign pillars
    void buyLand(sf::Vector2f mouse, sf::RenderWindow &window);
};


#endif //V2CPSE2_EXAMPLES_SHOP_HPP
