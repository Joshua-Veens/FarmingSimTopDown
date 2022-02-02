#ifndef V2CPSE2_EXAMPLES_TRACTOR_HPP
#define V2CPSE2_EXAMPLES_TRACTOR_HPP

#include "vehicle.hpp"
#include "rectangle.hpp"
#include "farmhouse.hpp"
#include "saveHouse.hpp"
#include "dirt.hpp"
#include "harvester.hpp"
#include "inventory.hpp"
#include "marketplace.hpp"
#include <memory>


class tractor : public vehicle{

private:
    enum tractorTypes{trekker=0, seeder=1, trailer=2};
    enum seederTypes{wheatSeeds=0, cornSeeds=1};
    seederTypes active_seeds = wheatSeeds;
    tractorTypes active_type = trekker;
    sf::Texture image;
    sf::Sprite sprite;
    int savedRotation = 0;
    sf::FloatRect seeder_collider;
    sf::FloatRect tractor_collider;
    sf::FloatRect trailer_collider;
    rectangle blokje;
    type currentCrop = wheat;
    std::string text_string;
    sf::Font font;
    sf::Text text;
    sf::Color color = sf::Color::White;
    sf::Sprite wheatSprite;
    sf::Sprite cornSprite;
    sf::Texture wheatImage;
    sf::Texture cornImage;
    unsigned int wheatCount = 0;
    unsigned int cornCount = 0;


public:
    tractor( sf::Vector2f position);

    void draw( sf::RenderWindow & window ) override;

    void move( sf::Vector2f delta, std::vector<drawable *> objects) override;

    void update(std::vector<std::vector<dirt *>> farmlands);

    void overloadCrop(harvester * combine);

    void depositCrop(sf::RenderWindow & window, inventory * silo);

    void sellCrops(sf::RenderWindow & window, marketplace * market);

    void setRotation( int rotation ) override;

    void changeToNormal() override;

    void changeToAction() override;

    void changeToTrailer() override;

    void updateCollider();

    int getRotation();

    sf::Vector2f getPosition();

    void setPosition(sf::Vector2f location);

    sf::FloatRect getCollider() override;

    void drawWheat(sf::RenderWindow &window);

    void drawCorn(sf::RenderWindow &window);

    void drawUnloadHelp(sf::RenderWindow &window, inventory * silo);

    void drawSellHelp(sf::RenderWindow &window, marketplace * market);

    void showCropAmount(sf::RenderWindow &window);

    int getActiveType();

    void setCrop(sf::Clock & clock);
};


#endif //V2CPSE2_EXAMPLES_TRACTOR_HPP
