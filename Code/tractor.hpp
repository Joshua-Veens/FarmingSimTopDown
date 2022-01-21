//
// Created by joshu on 20-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_TRACTOR_HPP
#define V2CPSE2_EXAMPLES_TRACTOR_HPP

#include "SFML/Graphics.hpp"
#include "vehicle.hpp"
#include "rectangle.hpp"

class tractor : public vehicle{
private:
    std::string filename = "trekkerjurgen.png";
    sf::Vector2f position;
    std::string type;
    sf::Texture image;
    sf::Sprite sprite;
    int savedRotation = 0;
    sf::FloatRect collider;
    rectangle blokje;
public:
    tractor( sf::Vector2f position, std::string type = "" );

    void draw( sf::RenderWindow & window ) override;

    void move( sf::Vector2f delta );

    void setRotation( int rotation );

    int getRotation();

    sf::Vector2f getPosition();

    void changeToTractor();

    void changeToSeeder();

    void updateCollider();

};


#endif //V2CPSE2_EXAMPLES_TRACTOR_HPP
