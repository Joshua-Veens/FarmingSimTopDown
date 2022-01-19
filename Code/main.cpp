#include "gameControl.hpp"


int main() {
    gameControl gameControl;
    gameControl.runGame();

//    sf::RenderWindow window{ sf::VideoMode{ 1920, 1080 }, "SFML window" };
//
//    picture trekker{ "trekkerJurgen.png", sf::Vector2f( 200, 200 )};
//    picture background{"level_1.png", sf::Vector2f(0,0)};

//    action actions[] = {
//            action( sf::Keyboard::W, sf::Keyboard::D,   [&](){ trekker.move( sf::Vector2f(  +1.0, -1.0 )); trekker.setRotation(45); }),
//            action( sf::Keyboard::W, sf::Keyboard::A,   [&](){ trekker.move( sf::Vector2f(  -1.0, -1.0 )); trekker.setRotation(315); }),
//            action( sf::Keyboard::S, sf::Keyboard::D,   [&](){ trekker.move( sf::Vector2f(  +1.0, +1.0 )); trekker.setRotation(135); }),
//            action( sf::Keyboard::S, sf::Keyboard::A,   [&](){ trekker.move( sf::Vector2f(  -1.0, +1.0 )); trekker.setRotation(225); }),
//
//            action( sf::Keyboard::W,    [&](){ trekker.move( sf::Vector2f(  0.0, -1.0 )); trekker.setRotation(0); }),
//            action( sf::Keyboard::S,  [&](){ trekker.move( sf::Vector2f(  0.0, +1.0 )); trekker.setRotation(180); }),
//            action( sf::Keyboard::A,  [&](){ trekker.move( sf::Vector2f( -1.0,  0.0 )); trekker.setRotation(270); }),
//            action( sf::Keyboard::D, [&](){ trekker.move( sf::Vector2f( +1.0,  0.0 )); trekker.setRotation(90); })
//    };

//    while (window.isOpen()) {
//        busy = false;
//        for( auto & action : actions ){
//            action();
//        }
//
//		window.clear();
//
//        background.draw(window);
//        trekker.draw(window);
//
//        window.display();
//
//        sf::sleep( sf::milliseconds( 5 ));
//
//        sf::Event event;
//	    while( window.pollEvent(event) ){
//			if( event.type == sf::Event::Closed ){
//				window.close();
//			}
//		}
//    }
}