//
// Created by joshu on 3-2-2022.
//

#ifndef V2CPSE2_EXAMPLES_MAP_HPP
#define V2CPSE2_EXAMPLES_MAP_HPP

#include "menu.hpp"

class map : public menu{
private:
    void create() override;

public:
    map(sf::RenderWindow &window, saver & Save);
};


#endif //V2CPSE2_EXAMPLES_MAP_HPP
