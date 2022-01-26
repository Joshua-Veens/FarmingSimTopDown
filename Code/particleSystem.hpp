//
// Created by joshu on 24-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_PARTICLESYSTEM_HPP
#define V2CPSE2_EXAMPLES_PARTICLESYSTEM_HPP

#include "SFML/Graphics.hpp"
#include "drawable.hpp"
#include <random>


class particle : public drawable {
private:
    unsigned int lifetime = rand() % ((25 - 10) + 1) + 10;
    sf::Vector2i position;
    sf::Vector2i velocity;
    sf::RectangleShape rect;
    sf::Color color;
    sf::Vector2f size;

public:
    particle(sf::Vector2i position, sf::Vector2i velocity, sf::Color color, sf::Vector2f size);

    void update();

    void draw(sf::RenderWindow &window) override;

    int getLife();

};

class particlePool {
private:
    unsigned int poolsize;
    std::vector<particle *> particles;

public:
    particlePool(unsigned int poolsize);

    void generate(sf::Vector2i position, int64_t elapsedTime, sf::Color color, sf::Vector2f size);

    void updatePool(sf::RenderWindow &window);

};


#endif //V2CPSE2_EXAMPLES_PARTICLESYSTEM_HPP
