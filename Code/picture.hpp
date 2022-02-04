//
// Created by joshu on 01/12/2021.

#ifndef V2CPSE2_EXAMPLES_PICTURE_HPP
#define V2CPSE2_EXAMPLES_PICTURE_HPP

#include "SFML/Graphics.hpp"
#include "drawable.hpp"
///@file
///@brief picture class derived ffom drawable, used to show pictures
class picture : public drawable {
private:
    std::string filename;
    sf::Vector2f position;
    std::string type;
    sf::Texture image;
    sf::Sprite sprite;
public:
    ///@brief constructor for picture class
    picture( std::string filename, sf::Vector2f position, std::string type = "" );
    ///@brief draws the picture on a given window
    void draw( sf::RenderWindow & window ) override;

};


#endif //V2CPSE2_EXAMPLES_PICTURE_HPP
