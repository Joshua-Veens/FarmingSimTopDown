//
// Created by joshu on 01/12/2021.

#ifndef V2CPSE2_EXAMPLES_PICTURE_HPP
#define V2CPSE2_EXAMPLES_PICTURE_HPP

#include "SFML/Graphics.hpp"
//#include "drawable.hpp"

class picture {
private:
    std::string filename;
    sf::Vector2f position;
    std::string type;
    sf::Texture image;
    sf::Sprite sprite;
    int savedRotation = 0;
public:
    picture( std::string filename, sf::Vector2f position, std::string type = "" );

    picture();

    void draw( sf::RenderWindow & window );

    void move( sf::Vector2f delta );

    void setRotation( int rotation );

    int getRotation();

    sf::Vector2f getPosition();

};


#endif //V2CPSE2_EXAMPLES_PICTURE_HPP
