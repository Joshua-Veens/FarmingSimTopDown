//
// Created by joshu on 20-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_TRACTOR_HPP
#define V2CPSE2_EXAMPLES_TRACTOR_HPP

#include "vehicle.hpp"
#include "rectangle.hpp"
#include "farmhouse.hpp"
#include "dirt.hpp"
#include <memory>

class tractor : public vehicle{
private:
    std::string filename = "trekkerjurgen.png";
    std::string type;
    sf::Texture image;
    sf::FloatRect seeder_collider;
    sf::FloatRect tractor_collider;
    rectangle blokje;

public:
    tractor( sf::Vector2f position, std::string type = "" );
    void draw( sf::RenderWindow & window ) override;
    void move( sf::Vector2f delta, drawable *object) override ;
    void update(std::vector<dirt *> farmland);
    void changeToNormal() override;
    void changeToAction() override ;
    void updateCollider();
};


#endif //V2CPSE2_EXAMPLES_TRACTOR_HPP
