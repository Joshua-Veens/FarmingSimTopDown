//
// Created by joshu on 01/12/2021.

#ifndef V2CPSE2_EXAMPLES_PICTURE_HPP
#define V2CPSE2_EXAMPLES_PICTURE_HPP

#include "SFML/Graphics.hpp"
#include "drawable.hpp"

class picture : public drawable {
private:
    std::string filename;
    sf::Vector2f position;
    std::string type;
    sf::Texture image;
    sf::Sprite sprite;
public:
    picture( std::string filename, sf::Vector2f position, std::string type = "" );

    picture();

    void draw( sf::RenderWindow & window ) override;

};


#endif //V2CPSE2_EXAMPLES_PICTURE_HPP
