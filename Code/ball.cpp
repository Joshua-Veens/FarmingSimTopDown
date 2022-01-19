#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball( sf::Vector2f position, sf::Vector2f velocity, sf::Color color, float size ):
	position{ position },
    velocity{ velocity },
    color{ color },
	size{ size }
{}

void ball::draw( sf::RenderWindow & window ) {
	circle.setRadius(size);
	circle.setPosition(position);
    circle.setFillColor(color);
	window.draw(circle);
}

void ball::move( sf::Vector2f delta ){
	position += delta;
}

//void ball::update() {
//    position += velocity;
//}
//
//void ball::update( sf::Vector2f update ) {
//    velocity += update;
//    if(velocity.x > 1){
//        velocity.x = 1;
//    }
//    if(velocity.x < -1){
//        velocity.x = -1;
//    }
//    if(velocity.y > 1){
//        velocity.y = 1;
//    }
//    if(velocity.y < -1){
//        velocity.y = -1;
//    }
//}

void ball::jump( sf::Vector2f target ){
	position = target;
}

void ball::jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}
