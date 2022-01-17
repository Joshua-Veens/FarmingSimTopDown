#ifndef V2CPSE2_EXAMPLES_WALL_HPP
#define V2CPSE2_EXAMPLES_WALL_HPP

#include "SFML/Graphics.hpp"
#include "drawable.hpp"

class rectangle : public drawable{
private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;

public:
    sf::RectangleShape vierkant;
    rectangle( sf::Vector2f position, sf::Vector2f size, sf::Color color);

    void draw( sf::RenderWindow & window );

    void move( sf::Vector2f delta );

    void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );
};


#endif //V2CPSE2_EXAMPLES_WALL_HPP
