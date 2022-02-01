#ifndef V2CPSE2_EXAMPLES_INVENTORY_HPP
#define V2CPSE2_EXAMPLES_INVENTORY_HPP

#include "drawable.hpp"
#include "dirt.hpp"
#include "rectangle.hpp"

class inventory : public drawable{
private:
    unsigned int wheatCount = 69420;
    unsigned int cornCount = 42069;
    sf::Texture image;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::FloatRect collider;
    rectangle blokje;
public:
    inventory(sf::Vector2f position);

    void draw( sf::RenderWindow & window ) override;

    unsigned int getWheat();

    unsigned int getCorn();

    void removeCrops();

};


#endif //V2CPSE2_EXAMPLES_INVENTORY_HPP
