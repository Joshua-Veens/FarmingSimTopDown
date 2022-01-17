//
// Created by joshu on 01/12/2021.
//

#ifndef V2CPSE2_EXAMPLES_PICTURE_HPP
#define V2CPSE2_EXAMPLES_PICTURE_HPP

#include "SFML/Graphics.hpp"
#include "drawable.hpp"

class picture : public drawable{
private:
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    picture( sf::Vector2f position, sf::Texture texture, sf::Sprite sprite );

    void draw ( sf::RenderWindow & window );

    void move( sf::Vector2f delta );

    void setRotation( int rotation );

};


#endif //V2CPSE2_EXAMPLES_PICTURE_HPP
