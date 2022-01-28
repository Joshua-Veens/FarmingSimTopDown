//
// Created by joshu on 20-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_VEHICLE_HPP
#define V2CPSE2_EXAMPLES_VEHICLE_HPP

#include "drawable.hpp"

class vehicle : public drawable
{
protected:
    virtual void draw(sf::RenderWindow &window){};
    int savedRotation = 0;
    sf::Sprite sprite;
    sf::Vector2f position = {0, 0};

public:
    vehicle(sf::Vector2f position);
    virtual void setRotation(int rotation);
    int getRotation();
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f location);
    virtual void move(sf::Vector2f delta, std::vector<drawable *> objects) = 0;
    virtual void changeToNormal() = 0;
    virtual void changeToAction() = 0;
};

#endif // V2CPSE2_EXAMPLES_VEHICLE_HPP
