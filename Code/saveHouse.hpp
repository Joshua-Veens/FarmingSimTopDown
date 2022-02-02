#ifndef SAVEHOUSE_HPP
#define SAVEHOUSE_HPP

#include "drawable.hpp"
#include "rectangle.hpp"

class saveHouse : public drawable{
private:
    sf::Vector2f position;
    sf::Texture image;
    sf::Sprite sprite;
    sf::FloatRect save_collider, house_collider;
    rectangle blokje;
public:
    saveHouse(sf::Vector2f position);

    void draw(sf::RenderWindow & window) override;

    sf::FloatRect getCollider() override;

    sf::FloatRect getSavePoint() override;
};


#endif //SAVEHOUSE_HPP
