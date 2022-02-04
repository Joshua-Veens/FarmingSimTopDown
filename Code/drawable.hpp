#ifndef V2CPSE2_EXAMPLES_DRAWABLE_HPP
#define V2CPSE2_EXAMPLES_DRAWABLE_HPP

#include <SFML/Graphics.hpp>


/// \brief drawable Class
/// \details This class holds all the drawables that are made in gamecontrol.

class drawable {
public:
    virtual void draw( sf::RenderWindow & window ){};

    virtual std::vector<sf::FloatRect> getColliders(){
        return std::vector<sf::FloatRect> {};
    };

    virtual sf::FloatRect getCollider(){
        return sf::FloatRect(0,0,0,0);
    }

    virtual sf::FloatRect getSavePoint(){
        return sf::FloatRect(0,0,0,0);
    }
};


#endif //V2CPSE2_EXAMPLES_DRAWABLE_HPP
