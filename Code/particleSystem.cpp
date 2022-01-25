//
// Created by joshu on 24-1-2022.
//

#include "particleSystem.hpp"
#include "iostream"

particle::particle(sf::Vector2i position, sf::Vector2i velocity, sf::Color color, sf::Vector2f size):
    position(position),
    velocity(velocity),
    color(color),
    size(size)
{}

void particle::draw(sf::RenderWindow &window) {
    rect.setPosition(sf::Vector2f(position));
    rect.setSize(sf::Vector2f(size.x,size.y));
    rect.setFillColor(color);
    window.draw(rect);
}

void particle::update() {
    position.x += velocity.x;
    position.y += velocity.y;
    lifetime--;
}

int particle::getLife() {
    return lifetime;
}

particlePool::particlePool(unsigned int poolsize):
    poolsize(poolsize)
{}

void particlePool::generate(sf::Vector2i position, int64_t elapsedTime, sf::Color color, sf::Vector2f size) {
    srand(elapsedTime);
    for(unsigned int i = 0; i < poolsize; i++){
        sf::Vector2i tempPosition = position;
        sf::Vector2i velocity = sf::Vector2i(0,0);
        int randomX = 0;
        int randomY = 0;
        int randomVx = 0;
        int randomVy = 0;
        randomX = rand() % ((32 - 1) + 1) + 1;
        randomY = rand() % ((32 - 1) + 1) + 1;
        randomVx = -1 + rand() % ( 1 - -1 + 1 );
        randomVy = -1 + rand() % ( 1 - -1 + 1 );
        tempPosition.x += randomX;
        tempPosition.y += randomY;
        velocity.x = randomVx;
        velocity.y = randomVy;
        particles.push_back(new particle(tempPosition, velocity, color, size));
    }
}

void particlePool::updatePool(sf::RenderWindow &window) {
    for(unsigned int i=0; i < particles.size(); i++) {
        particles[i]->draw(window);
        particles[i]->update();
        if (particles[i]->getLife() == 0){
            particles.erase(particles.begin() + i);
        }
    }
}