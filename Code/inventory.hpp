#ifndef V2CPSE2_EXAMPLES_INVENTORY_HPP
#define V2CPSE2_EXAMPLES_INVENTORY_HPP

#include "drawable.hpp"
#include "dirt.hpp"
#include "rectangle.hpp"

class inventory : public drawable{
private:
    unsigned int wheatCount = 1694200;
    unsigned int cornCount = 42069;
    sf::Texture image;
    sf::Sprite sprite;
    sf::Texture silo_texture;
    sf::Sprite silo_sprite;
    sf::Vector2f position;
    sf::FloatRect collider;
    sf::FloatRect silo_collider;
    rectangle blokje;
    std::string text_string;
    sf::Font font;
    sf::Text wheat_text;
    sf::Text corn_text;
    sf::Sprite wheatSprite;
    sf::Sprite cornSprite;
    sf::Texture wheatImage;
    sf::Texture cornImage;
public:
    inventory(sf::Vector2f position);

    void draw( sf::RenderWindow & window ) override;

    void drawSilo(sf::RenderWindow & window);

    int getWheat();

    int getCorn();

    void removeCrops();
    
    friend std::ostream &operator<<(std::ostream &lhs, inventory & inv)
    {
        return lhs << "Wheat: " << inv.wheatCount << " Corn: "<< inv.cornCount;
    }

    void addWheat(unsigned int wheat);

    void addCorn(unsigned int corn);

    void removeWheat(unsigned int wheat);

    void removeCorn(unsigned int corn);

    void drawInventory(sf::RenderWindow & window);

    void drawWheat(sf::RenderWindow &window);

    void drawCorn(sf::RenderWindow &window);

    sf::FloatRect getCollider() override;

    sf::FloatRect getDepositCollider();

    sf::Vector2f getPosition();

    sf::FloatRect getWheatTextCollider();

    sf::FloatRect getCornTextCollider();
};


#endif //V2CPSE2_EXAMPLES_INVENTORY_HPP
