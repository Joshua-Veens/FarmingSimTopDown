//
// Created by joshu on 27-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_INVENTORY_HPP
#define V2CPSE2_EXAMPLES_INVENTORY_HPP

#include "drawable.hpp"

enum type {wheat=0,corn=1};

class inventory : public drawable{
private:
    int wheatCount = 0;
    int cornCount = 0;
    type active_crop_type;
    std::string text_string;
    sf::Color color = sf::Color::White;
    const std::string font_file = "Xhers_Regular.otf";
    sf::Texture wheatImage;
    sf::Texture cornImage;
    sf::Sprite sprite;

public:
    inventory();

    void draw( sf::RenderWindow & window ) override;

    void drawWheat(sf::RenderWindow &window);

    void drawCorn(sf::RenderWindow &window);

    void setHarvest(type croptype);
};


#endif //V2CPSE2_EXAMPLES_INVENTORY_HPP
