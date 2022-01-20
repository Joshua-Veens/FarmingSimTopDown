//
// Created by joshu on 20-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_VEHICLE_HPP
#define V2CPSE2_EXAMPLES_VEHICLE_HPP

#include "drawable.hpp"

class vehicle : public drawable{
private:
    virtual void draw( sf::RenderWindow & window ){};
};


#endif //V2CPSE2_EXAMPLES_VEHICLE_HPP
