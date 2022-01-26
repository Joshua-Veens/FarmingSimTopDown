//
// Created by joshu on 24-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_HARVESTER_HPP
#define V2CPSE2_EXAMPLES_HARVESTER_HPP

#include "vehicle.hpp"
#include "SFML/Graphics.hpp"
#include <memory>
#include "dirt.hpp"

class harvester : public vehicle{
private:
    std::string filename = "harvester_closed.png";
    std::string type;
    sf::Texture image;
    sf::FloatRect collider;
//    rectangle blokje;

public:
    harvester(sf::Vector2f position, std::string type);

    void draw( sf::RenderWindow & window ) override;

    void move( sf::Vector2f delta );

    void update(std::vector<dirt *> farmland);

    void changeToNormal();

    void changeToAction();

    void updateCollider();
};


#endif //V2CPSE2_EXAMPLES_HARVESTER_HPP
