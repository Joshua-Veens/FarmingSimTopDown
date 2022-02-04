#ifndef V2CPSE2_EXAMPLES_INVENTORY_HPP
#define V2CPSE2_EXAMPLES_INVENTORY_HPP

#include "drawable.hpp"
#include "dirt.hpp"

/// \brief Inventory Class
/// \details This holds everything that is in the silo. It also has colliders so that when you collide with the vent you can store your crops in its inventory.

class inventory : public drawable{
private:
    unsigned int wheatCount = 69420;
    unsigned int cornCount = 42069;
    unsigned int weedCount = 6969;
    sf::Texture image;
    sf::Sprite sprite;
    sf::Texture silo_texture;
    sf::Sprite silo_sprite;
    sf::Vector2f position;
    sf::FloatRect collider;
    sf::FloatRect silo_collider;
    std::string text_string;
    sf::Font font;
    sf::Text wheat_text;
    sf::Text corn_text;
    sf::Text weed_text;
    sf::Sprite wheatSprite;
    sf::Sprite cornSprite;
    sf::Sprite weedSprite;
    sf::Texture wheatImage;
    sf::Texture cornImage;
    sf::Texture weedImage;

    void drawWheat(sf::RenderWindow &window);

    void drawCorn(sf::RenderWindow &window);

    void drawWeed(sf::RenderWindow &window);
public:
    /// @brief constructor of inventory
    inventory(sf::Vector2f position);

    /// @brief draws an inventory
    void draw( sf::RenderWindow & window ) override;

    /// @brief draws the silo on the screen
    void drawSilo(sf::RenderWindow & window);

    /// @brief send wheat amount
    int getWheat();

    /// @brief send corn amount
    int getCorn();

    /// @brief send weed amount
    int getWeed();

    /// @brief set a wheat amount
    void setWheat(int newWheat);

    /// @brief set a corn amount
    void setCorn(int newCorn);

    /// @brief set a weed amount
    void setWeed(int newWeed);

    /// @brief set all crops to 0
    void removeCrops();
    
    friend std::ostream &operator<<(std::ostream &lhs, inventory & inv)
    {
        return lhs << "Wheat: " << inv.wheatCount << " Corn: "<< inv.cornCount << "weed: " << inv.weedCount;
    }
    /// @brief adds an amount to wheat
    void addWheat(unsigned int wheat);

    /// @brief adds an amount to corn
    void addCorn(unsigned int corn);

    /// @brief adds an amount to weed
    void addWeed(unsigned int weed);

    /// @brief removes an amount of wheat
    void removeWheat(unsigned int wheat);

    /// @brief removes an amount of corn
    void removeCorn(unsigned int corn);

    /// @brief removes an amount of weed
    void removeWeed(unsigned int weed);

    /// @brief draws the icons for the crops
    void drawInventory(sf::RenderWindow & window);

    /// @brief sends box of the silo colliders
    sf::FloatRect getCollider() override;

    /// @brief sends the deposit collider box
    sf::FloatRect getDepositCollider();

    /// @brief sends current position
    sf::Vector2f getPosition();

    /// @brief sends box for wheat button
    sf::FloatRect getWheatTextCollider();

    /// @brief sends box for corn button
    sf::FloatRect getCornTextCollider();

    /// @brief sends box for weed button
    sf::FloatRect getWeedTextCollider();
};


#endif //V2CPSE2_EXAMPLES_INVENTORY_HPP
