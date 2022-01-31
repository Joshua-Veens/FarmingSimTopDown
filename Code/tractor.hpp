#ifndef V2CPSE2_EXAMPLES_TRACTOR_HPP
#define V2CPSE2_EXAMPLES_TRACTOR_HPP

#include "vehicle.hpp"
#include "rectangle.hpp"
#include "farmhouse.hpp"
#include "saveHouse.hpp"
#include "dirt.hpp"
#include <memory>


class tractor : public vehicle{

private:
    enum tractorTypes{trekker=0, seeder=1};
    tractorTypes active_type = trekker;
    sf::Texture image;
    sf::Sprite sprite;
    int savedRotation = 0;
    sf::FloatRect seeder_collider;
    sf::FloatRect tractor_collider;
    rectangle blokje;

public:
    tractor( sf::Vector2f position);

    void draw( sf::RenderWindow & window ) override;

    void move( sf::Vector2f delta, std::vector<drawable *> objects) override;

    void update(std::vector<dirt *> farmland);

    void setRotation( int rotation ) override;

    void changeToNormal() override;

    void changeToAction() override;

    void updateCollider();

    int getRotation();

    sf::Vector2f getPosition();

    void setPosition(sf::Vector2f location);

    sf::FloatRect getCollider() override;
};


#endif //V2CPSE2_EXAMPLES_TRACTOR_HPP