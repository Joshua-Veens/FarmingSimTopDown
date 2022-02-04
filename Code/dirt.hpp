// Justin van der Wiel 19-1-22

#ifndef DIRT_HPP
#define DIRT_HPP
#include "drawable.hpp"
#include "rectangle.hpp"
#include "particleSystem.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include "base64.hpp"
#include <iomanip>

enum type {wheat=0,corn=1,weed=2};

/// \brief dirt Class
/// \details This class makes a dirt plot on which you can farm multiple crops. It can be owned and not owned and has multiple growing stages.

class dirt : public drawable
{
public:
    enum property {notOwned=0, owned=1};
    enum state_t
    {
        unseeded = 0,
        seeded =1 ,
        growingStage1 = 2,
        growingStage2 = 3,
        growingStage3 = 4,
        growingStage4 = 5,
        grown =6
    };
private:
    property active_own = notOwned;
    state_t state = unseeded;
    sf::Vector2f position;
    std::vector<std::vector<std::string>> crops = {
        {"farmlands\\farmland.png", "wheat\\farmland_seeds.png",
         "wheat\\wheat_growing_1.png", "wheat\\wheat_growing_2.png",
         "wheat\\wheat_growing_3.png", "wheat\\wheat_growing_4.png",
         "wheat\\wheat_grown.png"},
        {"farmlands\\farmland.png", "corn\\farmland_seeds.png",
         "corn\\corn_growing_1.png", "corn\\corn_growing_2.png",
         "corn\\corn_growing_3.png", "corn\\corn_growing_4.png",
         "corn\\corn_grown.png"},
        {"farmlands\\farmland.png", "weed\\growing_1.png",
        "weed\\growing_2.png", "weed\\growing_3.png",
        "weed\\growing_4.png", "weed\\growing_5.png",
        "weed\\grown.png"}
    };

    type active_type = wheat;
    int cropcounter = 0;
    int ticks = 0;                                    // used to count if growing is done;
    int wait_time = rand() % ((270 - 150) + 1) + 150; // time between seeded and growing or growing and grown.
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock & clock;
    sf::FloatRect collider;
    particlePool particles = particlePool(40);

public:
    dirt(sf::Vector2f position, sf::Clock & clock);
    void draw(sf::RenderWindow &window);
    void seed();
    bool harvest(); // changes img_file back to unseeded if it's possible to harvest and returns true, retruns false if it not possible to harvest
    void update();
    sf::FloatRect getBounds();
    type getActiveType();
    void changeToWheat();
    void changeToCorn();
    void changeToWeed();
    void setPosition(sf::Vector2f newPos);
    state_t getState();
    void setState(state_t newState);
    void setToOwned();
    bool getOwned();
    friend std::ostream &operator<<(std::ostream &lhs, dirt Dirt)
    {
        return lhs << "Dirt@" <<  std::setfill('0') <<std::setw(5) <<  Dirt.position.x << ',' << std::setw(5) << std::setfill('0') << Dirt.position.y << " state=" << Dirt.state << " crop=" << Dirt.active_type << "owned=" << Dirt.getOwned();
    }

};

#endif
