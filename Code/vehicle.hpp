//
// Created by joshu on 20-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_VEHICLE_HPP
#define V2CPSE2_EXAMPLES_VEHICLE_HPP

#include "drawable.hpp"

class vehicle : public drawable{
private:
    virtual void draw( sf::RenderWindow & window ){};

public:
    int savedRotation = 0;
    sf::Sprite sprite;
    sf::Vector2f position = {0,0};


    void setRotation( int rotation );
    int getRotation();
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f location);
};


#endif //V2CPSE2_EXAMPLES_VEHICLE_HPP
