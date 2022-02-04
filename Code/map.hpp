//
// Created by joshu on 3-2-2022.
//

#ifndef V2CPSE2_EXAMPLES_MAP_HPP
#define V2CPSE2_EXAMPLES_MAP_HPP

/// \brief Map Class
/// \details The map class creates a new menu on which you can see the map.

#include "menu.hpp"

class map : public menu{
private:
    void create() override;

public:
    map(sf::RenderWindow &window, saver & Save);
};


#endif //V2CPSE2_EXAMPLES_MAP_HPP
