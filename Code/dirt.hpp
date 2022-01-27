// Justin van der Wiel 19-1-22

#ifndef DIRT_HPP
#define DIRT_HPP
#include "drawable.hpp"
#include "rectangle.hpp"
#include "particleSystem.hpp"
#include <SFML/Graphics.hpp>
#include <string>

enum type {wheat=0,corn=1};

class dirt : public drawable
{
private:
    enum state_t
    {
        unseeded,
        seeded,
        growingStage1,
        growingStage2,
        growingStage3,
        growingStage4,
        grown
    };
    state_t state = unseeded;
    sf::Vector2f position;
    std::vector<std::vector<std::string>> crops = {
            {"farmlands\\farmland.png", "farmlands\\farmland_seeds.png",
             "farmlands\\farmland_growing_1.png", "farmlands\\farmland_growing_2.png",
             "farmlands\\farmland_growing_3.png", "farmlands\\farmland_growing_4.png",
             "farmlands\\farmland_grown.png"}
    };
    type active_type = wheat;
    int cropcounter = 0;
    int ticks = 0;                               // used to count if growing is done;
    int wait_time = rand() % ((270 - 150) + 1) + 150;    // time between seeded and growing or growing and grown.
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock & clock;
    sf::FloatRect collider;
    particlePool particles = particlePool(40);

public:
    dirt(sf::Vector2f position, sf::Clock & clock, type active_type);
    void draw(sf::RenderWindow &window);
    void seed();
    bool harvest(); // changes img_file back to unseeded if it's possible to harvest and returns true, retruns false if it not possible to harvest
    void update();
    sf::FloatRect getBounds();
};

#endif