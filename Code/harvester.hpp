#ifndef V2CPSE2_EXAMPLES_HARVESTER_HPP
#define V2CPSE2_EXAMPLES_HARVESTER_HPP

#include "vehicle.hpp"
#include "SFML/Graphics.hpp"
#include <memory>
#include "dirt.hpp"
#include "farmhouse.hpp"
#include "saveHouse.hpp"


class harvester : public vehicle{
private:
    enum harversterTypes{harvesting=0, notHarvesting=1, overload=2};
    harversterTypes active_vehicle = notHarvesting;
    sf::Texture image;
    sf::Sprite sprite;
    std::string text_string;
    sf::Color color = sf::Color::White;
    const std::string font_file = "Xhers_Regular.otf";
    sf::Sprite wheatSprite;
    sf::Sprite cornSprite;
    sf::Texture wheatImage;
    sf::Texture cornImage;
    int savedRotation = 0;
    sf::FloatRect collider;
    sf::FloatRect auger_collider;
    rectangle blokje;
    unsigned int wheatCount = 0;
    unsigned int cornCount = 0;

public:
    harvester(sf::Vector2f position);

    void draw( sf::RenderWindow & window ) override;

    void move( sf::Vector2f delta, std::vector<drawable *> objects) override;

    void update(std::vector<dirt *> farmland);

    void setRotation( int rotation ) override;

    void checkIfFull();

    void addWheat();
    void addCorn();

    void showCropAmount(sf::RenderWindow &window);
    void drawWheat(sf::RenderWindow &window);
    void drawCorn(sf::RenderWindow &window);

    void changeToNormal() override;

    void changeToAction() override;

    void changeToTrailer() override;

    void changeToFull();

    void updateCollider();

    int getRotation();

    sf::Vector2f getPosition();

    sf::FloatRect getCollider() override;

    sf::FloatRect getAugerCollider();

    int getActiveType();

    int getWheat();

    int getCorn();

    void setWheatCount(unsigned int wheat);

    void setCornCount(unsigned int corn);
};


#endif //V2CPSE2_EXAMPLES_HARVESTER_HPP