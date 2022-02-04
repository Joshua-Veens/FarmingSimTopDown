#ifndef V2CPSE2_EXAMPLES_TRACTOR_HPP
#define V2CPSE2_EXAMPLES_TRACTOR_HPP

#include "vehicle.hpp"
#include "farmhouse.hpp"
#include "dirt.hpp"
#include "harvester.hpp"
#include "inventory.hpp"
#include "marketplace.hpp"
#include <memory>

///@file this file contains the class that creates the object tractor
///@details tractor class draws the tractor with corresponding colliders
class tractor : public vehicle{
private:
    enum tractorTypes{trekker=0, seeder=1, trailer=2};
    enum seederTypes{wheatSeeds=0, cornSeeds=1, weedSeeds=2};
    enum sizeTypes{small=0, big=1};
    sizeTypes active_size = small;
    seederTypes active_seeds = wheatSeeds;
    tractorTypes active_type = trekker;
    sf::Texture image;
    sf::Sprite sprite;
    int savedRotation = 0;
    sf::FloatRect seeder_collider;
    sf::FloatRect tractor_collider;
    sf::FloatRect trailer_collider;
    type currentCrop = wheat;
    std::string text_string;
    sf::Font font;
    sf::Text text;
    sf::Color color = sf::Color::White;
    sf::Sprite wheatSprite;
    sf::Sprite cornSprite;
    sf::Sprite weedSprite;
    sf::Texture wheatImage;
    sf::Texture cornImage;
    sf::Texture weedImage;
    unsigned int wheatCount = 0;
    unsigned int cornCount = 0;
    unsigned int weedCount = 0;

    void updateCollider();

    void drawWheat(sf::RenderWindow &window, sf::Vector2f position);

    void drawCorn(sf::RenderWindow &window, sf::Vector2f position);

    void drawWeed(sf::RenderWindow &window, sf::Vector2f position);

    void drawUnloadHelp(sf::RenderWindow &window, inventory * silo);

    void drawSellHelp(sf::RenderWindow &window, marketplace * market);
public:
    ///@brief tractor class constructor
    tractor( sf::Vector2f position);

    ///@brief draws the tractor
    void draw( sf::RenderWindow & window ) override;

    ///@brief Moves the tractor at the right speed and checks if the tractor collides with a building
    void move( sf::Vector2f delta, std::vector<drawable *> objects) override;

    ///@brief updates the farmlands with which the seeder collides
    void update(std::vector<std::vector<dirt *>> farmlands);

    ///@brief checks if active_type is a trailer and if the trailer collider intersects with the auger collider from the
    ///harvester and than unloads the crops form the harvester into the trailer
    void overloadCrop(harvester * combine);

    ///@brief deposits crops from the trailer into the silo or if clicked on the silo loads crops into the trailer
    void depositCrop(sf::RenderWindow & window, inventory * silo);

    ///@brief sells the crops from the trailer to the marketplace
    void sellCrops(sf::RenderWindow & window, marketplace * market);

    ///@brief rotates the sprite from the tractor
    void setRotation( int rotation ) override;

    ///@brief changes image to normal tractor
    void changeToNormal() override;

    ///@brief changes image to tractor with seeder
    void changeToAction() override;

    ///@brief changes image to tractor with trailer
    void changeToTrailer() override;

    ///@brief returns the rotation of the sprite 0, 180, 270, or 90
    int getRotation();

    ///@brief returns the position of the tractor
    sf::Vector2f getPosition();

    ///@brief changes position to newly given position
    void setPosition(sf::Vector2f location);

    ///@brief returns the tractor_collider
    sf::FloatRect getCollider() override;

    ///@brief draws the amount of each crop on the screen
    void showCropAmount(sf::RenderWindow &window, sf::Vector2f position);

    ///@brief draws which crop is being seeded on the screen
    void drawWhatSeeding(sf::RenderWindow &window, sf::Vector2f position);

    ///@brief returns the int of the active_type
    int getActiveType();

    ///@brief changes current active_seeds
    void setCrop(sf::Clock & clock);

    ///@brief returns the int of the active_size
    int getSize();

    ///@brief sets new active_size
    void setSize(bool size);

    ///@brief sets new active_type
    void setState(int newType);
    ///@brief ostream operator for tractor, useful for saving too
    friend std::ostream & operator<<(std::ostream& lhs, tractor &trekker){
        return lhs << "wheat: " << trekker.wheatCount << " corn: " << trekker.cornCount << " weed: " << trekker.weedCount << " size: " << trekker.active_size << " active_type: " << trekker.active_type;
    }

    ///@brief sets new wheatCount
    void setWheat(int newWheat);

    ///@brief sets new cornCount
    void setCorn(int newCorn);

    ///@brief sets new weedCount
    void setWeed(int newWeed);
};


#endif //V2CPSE2_EXAMPLES_TRACTOR_HPP
