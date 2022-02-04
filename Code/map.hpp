//
// Created by joshu on 3-2-2022.
//

#ifndef V2CPSE2_EXAMPLES_MAP_HPP
#define V2CPSE2_EXAMPLES_MAP_HPP

#include "menu.hpp"
///@file contains map class which inherits from menu(see menu.hpp)
///@details map class is a type of menu that shows the map

class map : public menu{
private:
    void create() override;

public:
    ///@brief constructor for map class
    map(sf::RenderWindow &window, saver & Save);
};


#endif //V2CPSE2_EXAMPLES_MAP_HPP
