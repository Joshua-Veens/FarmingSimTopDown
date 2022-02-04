#ifndef V2CPSE2_EXAMPLES_HARVESTER_HPP
#define V2CPSE2_EXAMPLES_HARVESTER_HPP

#include "vehicle.hpp"
#include "SFML/Graphics.hpp"
#include <memory>
#include "dirt.hpp"
#include "farmhouse.hpp"

/// \brief Harvester Class
/// \details This class creates the harvester. With it you can harvest the crops that are planted by the tractor from the dirt class.

class harvester : public vehicle
{
private:
    enum harversterTypes
    {
        harvesting = 0,
        notHarvesting = 1,
        overload = 2
    };
    enum sizeTypes
    {
        small = 0,
        big = 1
    };
    sizeTypes active_size = small;
    harversterTypes active_vehicle = notHarvesting;
    sf::Texture image;
    sf::Sprite sprite;
    std::string text_string;
    sf::Color color = sf::Color::White;
    const std::string font_file = "Xhers_Regular.otf";
    sf::Sprite wheatSprite;
    sf::Sprite cornSprite;
    sf::Sprite weedSprite;
    sf::Texture wheatImage;
    sf::Texture cornImage;
    sf::Texture weedImage;

    sf::Font font;
    sf::Text text;
    int savedRotation = 0;
    sf::FloatRect collider;
    sf::FloatRect auger_collider;
    unsigned int wheatCount = 0;
    unsigned int cornCount = 0;
    unsigned int weedCount = 0;

public:
    harvester(sf::Vector2f position);

    void draw(sf::RenderWindow &window) override;

    void move(sf::Vector2f delta, std::vector<drawable *> objects) override;

    void update(std::vector<std::vector<dirt *>> farmlands);

    void setRotation(int rotation) override;

    void checkIfFull();

    void addWheat();

    void addCorn();

    void addWeed();

    void showCropAmount(sf::RenderWindow &window, sf::Vector2f position);

    void drawWheat(sf::RenderWindow &window, sf::Vector2f position);

    void drawCorn(sf::RenderWindow &window, sf::Vector2f position);

    void drawWeed(sf::RenderWindow &window, sf::Vector2f position);

    void drawWeed(sf::RenderWindow &window);

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

    int getWeed();

    void setWheatCount(unsigned int wheat);

    void setCornCount(unsigned int corn);

    void setWeedCount(unsigned int weed);

    int getSize();

    void setSize(bool size);

    void setState(int newType);

    friend std::ostream &operator<<(std::ostream &lhs, harvester &combine)
    {
        return lhs << "wheat: " << combine.wheatCount << " corn: " << combine.cornCount << " weed: " << combine.weedCount << " size: " << combine.active_size << " active_type: " << combine.active_vehicle;
    }
};

#endif // V2CPSE2_EXAMPLES_HARVESTER_HPP