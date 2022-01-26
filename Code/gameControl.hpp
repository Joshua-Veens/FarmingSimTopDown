//
// Created by joshu on 19-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_GAMECONTROL_HPP
#define V2CPSE2_EXAMPLES_GAMECONTROL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "picture.hpp"
#include "action.hpp"
#include "dirt.hpp"
#include "tractor.hpp"
#include "harvester.hpp"
#include "menu.hpp"
#include "pauseMenu.hpp"
#include "farmhouse.hpp"

class gameControl
{
private:
    sf::RenderWindow window{sf::VideoMode{1920, 1080}, "SFML window",sf::Style::Fullscreen};
    bool busy = false;
    //    sf::Time elapsedTime, updateTime = sf::milliseconds(20);
    sf::Clock clock;
    menu Menu = menu(window);
    bool tractorOrHarvester = true;
    pause_menu pMenu = pause_menu(window);

    std::vector<std::shared_ptr<drawable>> objects = {
        std::shared_ptr<drawable>(new picture{"level_1.png", sf::Vector2f(0, 0)}),
        std::shared_ptr<drawable>(new tractor{sf::Vector2f(200, 200), "trekker"}),
        std::shared_ptr<drawable>(new harvester{sf::Vector2f(200, 200), "notHarvesting"}),
        std::shared_ptr<drawable>(new farmhouse{sf::Vector2f(75, 450)})};

    tractor *trekker = dynamic_cast<tractor *>(objects[1].get());
    harvester *combine = dynamic_cast<harvester *>(objects[2].get());
    farmhouse *barn = dynamic_cast<farmhouse *>(objects[3].get());

    std::vector<dirt *> farmland {};

    action actions[8] = {
        //            action( sf::Keyboard::W, sf::Keyboard::D,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  +1.0, -1.0 )); objectlist["Trekker"].setRotation(45);} ),
        //            action( sf::Keyboard::W, sf::Keyboard::A,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  -1.0, -1.0 )); objectlist["Trekker"].setRotation(315); }),
        //            action( sf::Keyboard::S, sf::Keyboard::D,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  +1.0, +1.0 )); objectlist["Trekker"].setRotation(135); }),
        //            action( sf::Keyboard::S, sf::Keyboard::A,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  -1.0, +1.0 )); objectlist["Trekker"].setRotation(225); }),

        action(sf::Keyboard::W, [&](){ movement(sf::Vector2f(0.0, -4.0), 0);}),
        action(sf::Keyboard::S, [&](){ movement(sf::Vector2f(0.0, +4.0), 180);}),
        action(sf::Keyboard::A, [&](){ movement(sf::Vector2f(-4.0,0.0), 270);}),
        action(sf::Keyboard::D, [&](){ movement(sf::Vector2f(+4.0,0.0), 90);}),

        action(sf::Keyboard::Num1, [&](){ changeToNormal(); }),
        action(sf::Keyboard::Num2, [&](){ changeToAction(); }),
        action(sf::Keyboard::R, [&](){ swapVehicle(); }),

        action(sf::Keyboard::Escape, [this]
               {if(Menu.getActive() || pMenu.getActive()){
                return;
            } pMenu.show(); })};

public:
    void runGame() {
        makeFarmLand(36,16);
        if (window.isOpen()){
            Menu.show();
        }
        while (window.isOpen()){
            for (auto &action : actions){
                action.setBusy(busy);
            }
            for (auto &action : actions){
                action();
            }

//            sf::Vector2f positionTractor = trekker->getPosition();
//            particle.setEmitter(positionTractor);

            trekker->update(farmland);
            combine->update(farmland);
            render();

            //sf::sleep(sf::milliseconds(5));
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
            //            clock.restart();

            sf::Event event;
            sf::View view = window.getDefaultView();
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

            }
        }
    }

    void render(){
        window.clear();
        for (auto &object : objects) {
            object->draw(window);
        }
        window.display();
    }

    void swapVehicle(){
        sf::Time time = clock.getElapsedTime();
        clock.restart();
        if(time.asMilliseconds() > 500){
            tractorOrHarvester = !tractorOrHarvester;
        }
    }

    void movement(sf::Vector2f speed, int rotation){
        if(tractorOrHarvester){
            trekker->move(speed, barn); trekker->setRotation(rotation);
        }else{
            combine->move(speed, barn); combine->setRotation(rotation);
        }
    }

    void changeToNormal(){
        if(tractorOrHarvester){
            trekker->changeToNormal();
        }else{
            combine->changeToNormal();
        }
    }

    void changeToAction(){
        if(tractorOrHarvester){
            trekker->changeToAction();
        }else{
            combine->changeToAction();
        }
    }

    void makeFarmLand(unsigned int width, unsigned int height){
        int x = 600;
        int y = 200;
        for(unsigned int i=0; i < height; i++){
            for(unsigned int j=0; j < width; j++){
                objects.insert( objects.begin()+1,std::shared_ptr<drawable>(new dirt{sf::Vector2f(x, y), clock}));
                farmland.push_back(dynamic_cast<dirt *>(objects[1].get()));
                x += 32;
            }
            x = 600;
            y += 32;
        }
    }
};

#endif // V2CPSE2_EXAMPLES_GAMECONTROL_HPP
