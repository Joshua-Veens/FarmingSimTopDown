//
// Created by joshu on 19-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_GAMECONTROL_HPP
#define V2CPSE2_EXAMPLES_GAMECONTROL_HPP

#include "SFML/Graphics.hpp"
#include <iostream>
#include "picture.hpp"
#include "action.hpp"
#include "dirt.hpp"

class gameControl {
private:
    sf::RenderWindow window{ sf::VideoMode{ 1920, 1080 }, "SFML window" };
    bool busy = false;
    sf::Time elapsedTime, updateTime = sf::milliseconds(20);
    sf::Clock clock;

    std::map<std::string, picture> backgroundlist = {
            {"background", picture("level_1.png", sf::Vector2f(0,0))}
    };

    std::map<std::string, picture> objectlist = {
            {"Trekker", picture("trekkerjurgen.png", sf::Vector2f( 200, 200 ), "trekker")},
            {"farmhouse", picture("farmhouse.png", sf::Vector2f(100, 450))}
    };

    std::map<std::string, dirt> farmlandlist = {
            {"farmlandR_1.1", sf::Vector2f(600, 200 )},
            {"farmlandR_1.2", sf::Vector2f(728, 200 )},
            {"farmland_R1.3", sf::Vector2f(856, 200 )},
            {"farmlandR_2.1", sf::Vector2f(600, 328 )},
            {"farmlandR_2.2", sf::Vector2f(728, 328 )},
            {"farmlandR_2.3", sf::Vector2f(856, 328 )},
            {"farmlandR_3.1", sf::Vector2f(600, 456 )},
            {"farmlandR_3.2", sf::Vector2f(728, 456 )},
            {"farmlandR_3.3", sf::Vector2f(856, 456 )},
            {"farmlandR_4.1", sf::Vector2f(600, 584 )},
            {"farmlandR_4.2", sf::Vector2f(728, 584 )},
            {"farmlandR_4.3", sf::Vector2f(856, 584 )}
    };

    action actions[6] = {
//            action( sf::Keyboard::W, sf::Keyboard::D,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  +1.0, -1.0 )); objectlist["Trekker"].setRotation(45);} ),
//            action( sf::Keyboard::W, sf::Keyboard::A,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  -1.0, -1.0 )); objectlist["Trekker"].setRotation(315); }),
//            action( sf::Keyboard::S, sf::Keyboard::D,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  +1.0, +1.0 )); objectlist["Trekker"].setRotation(135); }),
//            action( sf::Keyboard::S, sf::Keyboard::A,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  -1.0, +1.0 )); objectlist["Trekker"].setRotation(225); }),

            action( sf::Keyboard::W,    [&](){ objectlist["Trekker"].move( sf::Vector2f(  0.0, -4.0 )); objectlist["Trekker"].setRotation(0); }),
            action( sf::Keyboard::S,    [&](){ objectlist["Trekker"].move( sf::Vector2f(  0.0, +4.0 )); objectlist["Trekker"].setRotation(180); }),
            action( sf::Keyboard::A,    [&](){ objectlist["Trekker"].move( sf::Vector2f( -4.0,  0.0 )); objectlist["Trekker"].setRotation(270); }),
            action( sf::Keyboard::D,    [&](){ objectlist["Trekker"].move( sf::Vector2f( +4.0,  0.0 )); objectlist["Trekker"].setRotation(90); }),
            action( sf::Keyboard::Num1, [&](){ changeToTractor(); }),
            action( sf::Keyboard::Num2, [&](){ changeToSeeder(); })
    };

public:

    void runGame() {
        while (window.isOpen()) {
            for (auto &action: actions) {
                action.setBusy(busy);
            }
            for (auto &action: actions) {
                action();
            }

            sf::sleep( sf::milliseconds(5));
//            sf::Time lag = sf::milliseconds(0);
//            clock.restart();
//
//            sf::Time elapsed = clock.getElapsedTime();
//            lag += elapsed;
//
//            while (lag >= updateTime){
//                update();
//                lag -= updateTime;
//            }
            render();
//            clock.restart();


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
        for(auto & background : backgroundlist){
            background.second.draw(window);
        }
        for(auto & farmland : farmlandlist){
            farmland.second.draw(window);
        }
        for(auto & picture : objectlist){
            picture.second.draw(window);
        }
        window.display();
    }

    void changeToTractor(){
        sf::Vector2f position = objectlist["Trekker"].getPosition();
        int rotatie = objectlist["Trekker"].getRotation();
        objectlist.at("Trekker") = picture("trekkerjurgen.png", position, "trekker");
        objectlist["Trekker"].setRotation(rotatie);
    }

    void changeToSeeder(){
        sf::Vector2f position = objectlist["Trekker"].getPosition();
        int rotatie = objectlist["Trekker"].getRotation();
        objectlist.at("Trekker") = picture("trekkerseeder.png", position, "trekker");
        objectlist["Trekker"].setRotation(rotatie);
    }

};


#endif //V2CPSE2_EXAMPLES_GAMECONTROL_HPP
