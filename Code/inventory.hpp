#ifndef V2CPSE2_EXAMPLES_INVENTORY_HPP
#define V2CPSE2_EXAMPLES_INVENTORY_HPP

#include "drawable.hpp"
#include "dirt.hpp"
#include "rectangle.hpp"

class inventory : public drawable{
private:
    unsigned int wheatCount = 0;
    unsigned int cornCount = 0;
    unsigned int weedCount = 0;
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
    sf::Text weed_text;
    sf::Sprite wheatSprite;
    sf::Sprite cornSprite;
    sf::Sprite weedSprite;
    sf::Texture wheatImage;
    sf::Texture cornImage;
    sf::Texture weedImage;
public:
    inventory(sf::Vector2f position);

    void draw( sf::RenderWindow & window ) override;

    void drawSilo(sf::RenderWindow & window);

    int getWheat();

    int getCorn();

    int getWeed();


    void setWheat(int newWheat);

    void setCorn(int newCorn);

    void setWeed(int newWeed);

    void removeCrops();
    
    friend std::ostream &operator<<(std::ostream &lhs, inventory & inv)
    {
        return lhs << "Wheat: " << inv.wheatCount << " Corn: "<< inv.cornCount;
    }

    void addWheat(unsigned int wheat);

    void addCorn(unsigned int corn);

    void addWeed(unsigned int weed);

    void removeWheat(unsigned int wheat);

    void removeCorn(unsigned int corn);

    void removeWeed(unsigned int weed);

    void drawInventory(sf::RenderWindow & window);

    void drawWheat(sf::RenderWindow &window);

    void drawCorn(sf::RenderWindow &window);

    void drawWeed(sf::RenderWindow &window);

    sf::FloatRect getCollider() override;

    sf::FloatRect getDepositCollider();

    sf::Vector2f getPosition();

    sf::FloatRect getWheatTextCollider();

    sf::FloatRect getCornTextCollider();

    sf::FloatRect getWeedTextCollider();
};


#endif //V2CPSE2_EXAMPLES_INVENTORY_HPP
