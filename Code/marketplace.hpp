//
// Created by joshu on 28-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_MARKETPLACE_HPP
#define V2CPSE2_EXAMPLES_MARKETPLACE_HPP

#include "drawable.hpp"
#include "rectangle.hpp"

class marketplace : public drawable{
private:
    float money = 100000;
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
    marketplace(sf::Vector2f position);

    void draw(sf::RenderWindow & window) override;

    sf::FloatRect getCollider() override;

    sf::FloatRect getSellCollider();

    sf::Vector2f getPosition();

    void sellCrops(float wheat, float corn, float weed);

    void drawMoney(sf::RenderWindow & window, sf::Vector2f moneyPosition);
    
    float getMoney();
    
    void addMoney(float moneyToAdd);
    
    void setMoney(float allMoney);
    
    void removeMoney(float moneyToRemove);
    
    friend std::ostream & operator<<(std::ostream & lhs, marketplace & Market){
        return  lhs << "Money:" << Market.getMoney();
    }

//    void sellAll();

//    void create() override;
};


#endif //V2CPSE2_EXAMPLES_MARKETPLACE_HPP
