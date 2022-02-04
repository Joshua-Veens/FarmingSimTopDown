#ifndef V2CPSE2_EXAMPLES_SHOP_HPP
#define V2CPSE2_EXAMPLES_SHOP_HPP

#include "dirt.hpp"
#include "marketplace.hpp"

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
    shop(std::vector<std::vector<dirt *>> & farmlands, marketplace * market, sf::Clock & clock);

    void draw(sf::RenderWindow &window);

    void addForSaleSign(sf::Vector2f position);

    void buyLand(sf::Vector2f mouse, sf::RenderWindow &window);
};


#endif //V2CPSE2_EXAMPLES_SHOP_HPP
