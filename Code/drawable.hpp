//
// Created by joshu on 01/12/2021.
//

#ifndef V2CPSE2_EXAMPLES_DRAWABLE_HPP
#define V2CPSE2_EXAMPLES_DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class drawable {
public:
    virtual void draw( sf::RenderWindow & window ){};

    virtual std::vector<sf::FloatRect> getColliders(){
        return std::vector<sf::FloatRect> {};
    };

    virtual sf::FloatRect getChangeCollider(){
        return sf::FloatRect(0,0,0,0);
    }
};


#endif //V2CPSE2_EXAMPLES_DRAWABLE_HPP
