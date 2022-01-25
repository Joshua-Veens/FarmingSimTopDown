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


























//private:
//
//    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
//        // apply the transform
//        states.transform *= getTransform();
//
//        // our particles don't use a texture
//        states.texture = NULL;
//
//        // draw the vertex array
//        target.draw(m_vertices, states);
//    }
//
//    struct Particle {
//        sf::Vector2f velocity;
//        sf::Time lifetime;
//    };
//
//    void resetParticle(std::size_t index) {
//        // give a random velocity and lifetime to the particle
//        float angle = (std::rand() % 360) * 3.14f / 180.f;
//        float speed = (std::rand() % 50) + 50.f;
//        m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
//        m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);
//
//        // reset the position of the corresponding vertex
//        m_vertices[index].position = m_emitter;
//    }
//
//    std::vector<Particle> m_particles;
//    sf::VertexArray m_vertices;
//    sf::Time m_lifetime;
//    sf::Vector2f m_emitter;
//
//public:
//
//    particleSystem(unsigned int count) :
//            m_particles(count),
//            m_vertices(sf::Points, count),
//            m_lifetime(sf::seconds(3)),
//            m_emitter(0, 0)
//    {}
//
//    void setEmitter(sf::Vector2f position) {
//        m_emitter = position;
//    }
//
//    void update(sf::Time elapsed){
//        for (std::size_t i = 0; i < m_particles.size(); ++i) {
//            // update the particle lifetime
//            Particle& p = m_particles[i];
//            p.lifetime -= elapsed;
//
//            // if the particle is dead, respawn it
//            if (p.lifetime <= sf::Time::Zero)
//                resetParticle(i);
//
//            // update the position of the corresponding vertex
//            m_vertices[i].position += p.velocity * elapsed.asSeconds();
//
//            // update the alpha (transparency) of the particle according to its lifetime
//            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
//            m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
//        }
//    }
//
//};


#endif //V2CPSE2_EXAMPLES_PARTICLESYSTEM_HPP
