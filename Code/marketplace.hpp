// this file contains doxygen lines

#ifndef V2CPSE2_EXAMPLES_MARKETPLACE_HPP
#define V2CPSE2_EXAMPLES_MARKETPLACE_HPP


#include "drawable.hpp"

/// @file marketplace.hpp
/// @brief marketplace class
/// @details this class keeps track of the players amount of money

class marketplace : public drawable{
private:
    float money = 30000;
//    inventory * inv;
    sf::Texture image;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::FloatRect sell_collider;
    sf::FloatRect collider;
    std::string text_string;
    sf::Font font;
    sf::Text text;
public:

    /// @brief constructor of the marketplace
    marketplace(sf::Vector2f position);

    /// @brief draws the marketplace on the screen
    void draw(sf::RenderWindow & window) override;

    /// @brief sends collisition box of the marketplace
    sf::FloatRect getCollider() override;

    /// @brief sends collisition box of the sell part of the marketplace
    sf::FloatRect getSellCollider();

    /// @brief sends current position
    sf::Vector2f getPosition();

    /// @brief changes money amount of a player
    void sellCrops(float wheat, float corn, float weed);

    /// @brief draws the money amount of a player
    void drawMoney(sf::RenderWindow & window, sf::Vector2f moneyPosition);

    /// @brief sends the money amunt of a player
    float getMoney();

    /// @brief adds an amount of money to the currect money amount
    void addMoney(float moneyToAdd);

    /// @brief sets a money amount
    void setMoney(float allMoney);

    /// @brief removes an amount of money from the current money amount
    void removeMoney(float moneyToRemove);
    ///@brief ostream operator for marketplace
    friend std::ostream & operator<<(std::ostream & lhs, marketplace & Market){
        return  lhs << "Money:" << Market.getMoney();
    }

//    void sellAll();

//    void create() override;
};


#endif //V2CPSE2_EXAMPLES_MARKETPLACE_HPP
