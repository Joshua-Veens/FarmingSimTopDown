#ifndef V2CPSE2_EXAMPLES_HARVESTER_HPP
#define V2CPSE2_EXAMPLES_HARVESTER_HPP

#include "vehicle.hpp"
#include "SFML/Graphics.hpp"
#include <memory>
#include "dirt.hpp"
#include "farmhouse.hpp"

class harvester : public vehicle{
private:
    std::string filename = "harvester_closed.png";
    sf::Vector2f position;
    std::string type;
    sf::Texture image;
    sf::Sprite sprite;
    int savedRotation = 0;
    sf::FloatRect collider;
    rectangle blokje;

public:
    harvester(sf::Vector2f position, std::string type);

    void draw( sf::RenderWindow & window ) override;

    void move( sf::Vector2f delta, drawable *object);

    void update(std::vector<dirt *> farmland);

    void setRotation( int rotation ) override;

    void changeToNormal();

    void changeToAction();

    void updateCollider();

    int getRotation();

    sf::Vector2f getPosition();
};


#endif //V2CPSE2_EXAMPLES_HARVESTER_HPP