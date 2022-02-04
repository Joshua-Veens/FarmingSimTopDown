//this file contains doxygen lines
#ifndef V2CPSE2_EXAMPLES_VEHICLE_HPP
#define V2CPSE2_EXAMPLES_VEHICLE_HPP

#include "drawable.hpp"

/// @file vehicle.hpp
/// @brief the superclass vehicle
/// @details the class where vehicles get some og there characteristics

class vehicle : public drawable
{
protected:
    virtual void draw(sf::RenderWindow &window){};
    int savedRotation = 0;
    sf::Sprite sprite;
    sf::Vector2f position = {0, 0};

public:
    /// @brief contructor of vehicle
    vehicle(sf::Vector2f position);

    /// @brief sets the rotation of a vehicle
    virtual void setRotation(int rotation);

    /// @brief sends rotation of the vehicle
    int getRotation();

    /// @brief sends x and y position of the vehicle
    sf::Vector2f getPosition();

    /// @brief sets a position of the vehicle
    void setPosition(sf::Vector2f location);

    /// @brief virtual function for the movablity of vehicles
    virtual void move(sf::Vector2f delta, std::vector<drawable *> objects) = 0;

    /// @brief virtual function for the 'normal' state of a vehicle
    virtual void changeToNormal() = 0;

    /// @brief virtual function for the action state of a vehicle
    virtual void changeToAction() = 0;

    /// @brief virtual function for the dump state of a vehicle
    virtual void changeToTrailer() = 0;
};

#endif // V2CPSE2_EXAMPLES_VEHICLE_HPP
