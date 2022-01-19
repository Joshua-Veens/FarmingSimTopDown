#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class ball : public drawable{
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Color color;
    float size;

public:
    sf::CircleShape circle;
	ball( sf::Vector2f position, sf::Vector2f velocity, sf::Color color, float size = 30.0 );

	void draw( sf::RenderWindow & window );

	void move( sf::Vector2f delta );

	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );


};

#endif
