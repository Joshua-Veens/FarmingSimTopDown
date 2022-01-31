#ifndef V2CPSE2_EXAMPLES_HARVESTER_HPP
#define V2CPSE2_EXAMPLES_HARVESTER_HPP

#include "vehicle.hpp"
#include "SFML/Graphics.hpp"
#include <memory>
#include "dirt.hpp"
#include "farmhouse.hpp"
#include "saveHouse.hpp"
#include "inventory.hpp"


class harvester : public vehicle{
private:
    enum harversterTypes{harvesting=0, notHarvesting=1, full=2};
    harversterTypes active_type = notHarvesting;
    sf::Texture image;
    sf::Sprite sprite;
    int savedRotation = 0;
    sf::FloatRect collider;
    sf::FloatRect auger_collider;
    rectangle blokje;

public:
    harvester(sf::Vector2f position);

    void draw( sf::RenderWindow & window ) override;

    void move( sf::Vector2f delta, std::vector<drawable *> objects) override;

    void update(std::vector<dirt *> farmland);

    void setRotation( int rotation ) override;

    void checkIfFull(std::vector<dirt *> farmland);

    void changeToNormal() override;

    void changeToAction() override;

    void changeToTrailer() override;

    void changeToFull();

    void updateCollider();

    int getRotation();

    sf::Vector2f getPosition();

    sf::FloatRect getCollider() override;
};


#endif //V2CPSE2_EXAMPLES_HARVESTER_HPP