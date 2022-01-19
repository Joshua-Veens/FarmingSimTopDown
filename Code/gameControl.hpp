//
// Created by joshu on 19-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_GAMECONTROL_HPP
#define V2CPSE2_EXAMPLES_GAMECONTROL_HPP

#include <iostream>
#include "picture.hpp"
#include "action.hpp"
#include "SFML/Graphics.hpp"

class gameControl {
private:
    sf::RenderWindow window{ sf::VideoMode{ 1920, 1080 }, "SFML window" };
    bool busy = false;

    std::map<std::string, picture> objectlist = {
            {"Trekker", picture("trekkerJurgen.png", sf::Vector2f( 200, 200 ))},
            {"Background", picture("level_1.png", sf::Vector2f(0,0))}
    };

    action actions[8] = {
            action( sf::Keyboard::W, sf::Keyboard::D,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  +1.0, -1.0 )); objectlist["Trekker"].setRotation(45);} ),
            action( sf::Keyboard::W, sf::Keyboard::A,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  -1.0, -1.0 )); objectlist["Trekker"].setRotation(315); }),
            action( sf::Keyboard::S, sf::Keyboard::D,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  +1.0, +1.0 )); objectlist["Trekker"].setRotation(135); }),
            action( sf::Keyboard::S, sf::Keyboard::A,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  -1.0, +1.0 )); objectlist["Trekker"].setRotation(225); }),

            action( sf::Keyboard::W,    [&](){ objectlist["Trekker"].move( sf::Vector2f(  0.0, -1.0 )); objectlist["Trekker"].setRotation(0); }),
            action( sf::Keyboard::S,  [&](){ objectlist["Trekker"].move( sf::Vector2f(  0.0, +1.0 )); objectlist["Trekker"].setRotation(180); }),
            action( sf::Keyboard::A,  [&](){ objectlist["Trekker"].move( sf::Vector2f( -1.0,  0.0 )); objectlist["Trekker"].setRotation(270); }),
            action( sf::Keyboard::D, [&](){ objectlist["Trekker"].move( sf::Vector2f( +1.0,  0.0 )); objectlist["Trekker"].setRotation(90); })
    };

public:

    void runGame() {
        while (window.isOpen()) {
            actions->setBusy(busy);
            for (auto &action: actions) {
                action();
            }
            render();

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
        }
    }

    void render(){
        window.clear();
        for(auto & picture : objectlist){
            picture.second.draw(window);
        }
        window.display();
    }
};


#endif //V2CPSE2_EXAMPLES_GAMECONTROL_HPP
