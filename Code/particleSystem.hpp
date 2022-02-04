//
// Created by joshu on 24-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_PARTICLESYSTEM_HPP
#define V2CPSE2_EXAMPLES_PARTICLESYSTEM_HPP

#include "SFML/Graphics.hpp"
#include "drawable.hpp"
#include <random>

/// \brief Particle Class
/// \details This class creates one particle which will be moving in a random direction. And it will also have a random lifetime.

class particle : public drawable {
private:
    unsigned int lifetime = rand() % ((55 - 40) + 1) + 40;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape rect;
    sf::Color color;
    sf::Vector2f size;

public:
    particle(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, sf::Vector2f size);

    void update();

    void draw(sf::RenderWindow &window) override;

    int getLife();

};

/// \brief ParticlePool Class
/// \details In this class particles are generated and put into a vector. The vector will be drawn and when the lifetime of the particle is 0 it will be removed from the vector. Everytime the tractor or harvester collides with a dirt plot a new set of particles is generated.

class particlePool {
private:
    unsigned int poolsize;
    std::vector<particle *> particles;

public:
    particlePool(unsigned int poolsize);

    void generate(sf::Vector2f position, int64_t elapsedTime, sf::Color color, sf::Vector2f size);

    void updatePool(sf::RenderWindow &window);

};


#endif //V2CPSE2_EXAMPLES_PARTICLESYSTEM_HPP
