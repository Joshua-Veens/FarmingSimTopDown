#include <iostream>
#include <functional>
#include "SFML/Graphics.hpp"
#include "picture.hpp"

bool busy = false;
class action {
private:
    std::function< bool() > condition;
    std::function< void() > work;
public:
    action(
            std::function< bool() > condition,
            std::function< void() > work
    ) : condition( condition ),
        work( work )
    {}

    action(
            sf::Keyboard::Key key,
            std::function< void() > work
    ) :
            condition(
                    [ key ]()->bool { return sf::Keyboard::isKeyPressed( key ) && !busy; }
            ),
            work(work)
    {}

    action(
            sf::Keyboard::Key key1,
            sf::Keyboard::Key key2,
            std::function<void()> work
    ) :
            condition(
                    [ key1, key2 ]() -> bool { return sf::Keyboard::isKeyPressed(key1) && sf::Keyboard::isKeyPressed(key2) && !busy; }
            ),
            work(work)
    {}

    action(
            sf::Mouse::Button button,
            std::function< void() > work
    ) :
            condition(
                    [ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
            ),
            work(work)
    {}

    action(
            std::function< void() > work
    ) :
            condition(
                    []()->bool { return true; }
            ),
            work(work)
    {}

    void operator()(){
        if( condition() ){
            busy = true;
            work();
        }
    }
};


int main() {
    sf::RenderWindow window{ sf::VideoMode{ 1920, 1080 }, "SFML window" };

    picture image{ sf::Vector2f( 200, 200 ) ,sf::Texture(), sf::Sprite()};

    action actions[] = {
            action( sf::Keyboard::W, sf::Keyboard::D,   [&](){ image.move( sf::Vector2f(  +1.0, -1.0 )); image.setRotation(45); }),
            action( sf::Keyboard::W, sf::Keyboard::A,   [&](){ image.move( sf::Vector2f(  -1.0, -1.0 )); image.setRotation(315); }),
            action( sf::Keyboard::S, sf::Keyboard::D,   [&](){ image.move( sf::Vector2f(  +1.0, +1.0 )); image.setRotation(135); }),
            action( sf::Keyboard::S, sf::Keyboard::A,   [&](){ image.move( sf::Vector2f(  -1.0, +1.0 )); image.setRotation(225); }),
            
            action( sf::Keyboard::W,    [&](){ image.move( sf::Vector2f(  0.0, -1.0 )); image.setRotation(0); }),
            action( sf::Keyboard::S,  [&](){ image.move( sf::Vector2f(  0.0, +1.0 )); image.setRotation(180); }),
            action( sf::Keyboard::A,  [&](){ image.move( sf::Vector2f( -1.0,  0.0 )); image.setRotation(270); }),
            action( sf::Keyboard::D, [&](){ image.move( sf::Vector2f( +1.0,  0.0 )); image.setRotation(90); })
    };

    while (window.isOpen()) {
        busy = false;
        for( auto & action : actions ){
            action();
        }
		window.clear();

        image.draw(window);

        window.display();

        sf::sleep( sf::milliseconds( 2 ));

        sf::Event event;
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}
    }
}