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
    /// @brief constructor of the harvester
    harvester(sf::Vector2f position);

    /// @brief draws the harvester object
    void draw(sf::RenderWindow &window) override;

    /// @brief moves the harvester object over the screen
    void move(sf::Vector2f delta, std::vector<drawable *> objects) override;

    /// @brief updates the farmlands (dirt) to unseeded if harvestable
    void update(std::vector<std::vector<dirt *>> farmlands);

    /// @brief changes the rotation of the of the object's sprite
    void setRotation(int rotation) override;

    /// @brief checks if the harvester's inventory is full
    void checkIfFull();

    /// @brief adds an amount of wheat to the harvester's inventory
    void addWheat();

    /// @brief adds an amount of corn to the harvester's inventory
    void addCorn();

    /// @brief adds an amount of weed to the harvester's inventory
    void addWeed();

    /// @brief shows on the screen the amount of a crop type in inventory
    void showCropAmount(sf::RenderWindow &window, sf::Vector2f position);

    /// @brief draws the wheat symbol
    void drawWheat(sf::RenderWindow &window, sf::Vector2f position);

    /// @brief draws the corn symbol
    void drawCorn(sf::RenderWindow &window, sf::Vector2f position);

    /// @brief draws the weed symbol
    void drawWeed(sf::RenderWindow &window, sf::Vector2f position);

    /// @brief draws the weed symbol
    void drawWeed(sf::RenderWindow &window);

    /// @brief changes the harvester to 'normal'
    void changeToNormal() override;

    /// @brief sets the harvester to harvest
    void changeToAction() override;

    /// @brief sets the harvester to be able to unload in the trailer
    void changeToTrailer() override;

    /// @brief sets the harvester to full
    void changeToFull();

    /// @brief changes the collider as the harvester rotates
    void updateCollider();

    /// @brief send current rotation of the harvester
    int getRotation();

    /// @brief sends the current position of the harvester in a vector
    sf::Vector2f getPosition();

    /// @brief sends the collider box of the harvester
    sf::FloatRect getCollider() override;

    /// @brief sends the collider to dump harvesters invertory in the trailer
    sf::FloatRect getAugerCollider();


    /// @brief sends through player that is is a harvester
    int getActiveType();

    /// @brief sends the amount of wheat in inventory
    int getWheat();

    /// @brief sends the amount of corn in inventory
    int getCorn();

    ///@brief sends the amount of corn in inventory
    int getWeed();

    /// @brief changes the wheat amount in inventory
    void setWheatCount(unsigned int wheat);

    /// @brief changes the corn amount in inventory
    void setCornCount(unsigned int corn);

    /// @brief changes the weed amount in inventory
    void setWeedCount(unsigned int weed);

    /// @brief send the type of harvester (big / small)
    int getSize();

    /// @brief changes the type of harvester (big / small)
    void setSize(bool size);

    /// @brief sets the state of harvester  (nothing / harvesting / dumping)
    void setState(int newType);
    ///@brief ostream operator for harvester, prints data about harvester, also useful for saving
    friend std::ostream &operator<<(std::ostream &lhs, harvester &combine)
    {
        return lhs << "wheat: " << combine.wheatCount << " corn: " << combine.cornCount << " weed: " << combine.weedCount << " size: " << combine.active_size << " active_type: " << combine.active_vehicle;
    }
};

#endif // V2CPSE2_EXAMPLES_HARVESTER_HPP