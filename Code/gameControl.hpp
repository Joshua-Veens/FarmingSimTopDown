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
#include "player.hpp"

class gameControl
{
private:
    sf::RenderWindow window{sf::VideoMode{1920, 1080}, "SFML window"};
    bool busy = false;
    //    sf::Time elapsedTime, updateTime = sf::milliseconds(20);
    sf::Clock clock;
    menu Menu = menu(window);
    pause_menu pMenu = pause_menu(window);
    std::vector<std::shared_ptr<drawable>> objects = {
        std::shared_ptr<drawable>(new picture{"images\\level_1.png", sf::Vector2f(0, 0)}),
        std::shared_ptr<drawable>(new tractor{sf::Vector2f(200, 200)}),
        std::shared_ptr<drawable>(new harvester{sf::Vector2f(200, 200)}),
        std::shared_ptr<drawable>(new farmhouse{sf::Vector2f(75, 450)})};

    tractor *trekker = dynamic_cast<tractor *>(objects[1].get());
    harvester *combine = dynamic_cast<harvester *>(objects[2].get());
    farmhouse *barn = dynamic_cast<farmhouse *>(objects[3].get());
    std::array<vehicle *, 2> vehicles = {trekker, combine};
    player Player = player(vehicles);
    std::vector<dirt *> farmland{};
    action actions[8] = {
        //            action( sf::Keyboard::W, sf::Keyboard::D,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  +1.0, -1.0 )); objectlist["Trekker"].setRotation(45);} ),
        //            action( sf::Keyboard::W, sf::Keyboard::A,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  -1.0, -1.0 )); objectlist["Trekker"].setRotation(315); }),
        //            action( sf::Keyboard::S, sf::Keyboard::D,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  +1.0, +1.0 )); objectlist["Trekker"].setRotation(135); }),
        //            action( sf::Keyboard::S, sf::Keyboard::A,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  -1.0, +1.0 )); objectlist["Trekker"].setRotation(225); }),

        action(sf::Keyboard::W, [&]()
               { movement(sf::Vector2f(0.0, -4.0), 0); }),
        action(sf::Keyboard::S, [&]()
               { movement(sf::Vector2f(0.0, +4.0), 180); }),
        action(sf::Keyboard::A, [&]()
               { movement(sf::Vector2f(-4.0, 0.0), 270); }),
        action(sf::Keyboard::D, [&]()
               { movement(sf::Vector2f(+4.0, 0.0), 90); }),

        action(sf::Keyboard::Num1, [&]()
               { Player.getVehicle()->changeToNormal(); }),
        action(sf::Keyboard::Num2, [&]()
               { Player.getVehicle()->changeToAction(); }),
        action(sf::Keyboard::R, [&]()
               { Player.swapVehicle(clock); }),

        action(sf::Keyboard::Escape, [this]
               {if(Menu.getActive() || pMenu.getActive()){
                return;
            } pMenu.show(); })};

public:
    void runGame()
    {
        makeFarmLand(36, 16);
        if (window.isOpen())
        {
            Menu.show();
        }
        while (window.isOpen())
        { 
            for (auto &action : actions)
            {
                action.setBusy(busy);
            }
            for (auto &action : actions)
            {
                action();
            }

            //            sf::Vector2f positionTractor = trekker->getPosition();
            //            particle.setEmitter(positionTractor);

            trekker->update(farmland);
            combine->update(farmland);
            render();

            // sf::sleep(sf::milliseconds(5));
            //             sf::Time lag = sf::milliseconds(0);
            //             clock.restart();
            //
            //             sf::Time elapsed = clock.getElapsedTime();
            //             lag += elapsed;
            //
            //             while (lag >= updateTime){
            //                 update();
            //                 lag -= updateTime;
            //             }
            //             clock.restart();

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

    void render()
    {
        window.clear();
        for (auto &object : objects)
        {
            object->draw(window);
        }
        window.display();
    }

    void movement(sf::Vector2f speed, int rotation)
    {
        Player.getVehicle()->move(speed, barn);
        Player.getVehicle()->setRotation(rotation);
    }

    void changeToNormal()
    {
        Player.getVehicle()->changeToNormal();
    }

    void changeToAction()
    {
        Player.getVehicle()->changeToAction();
    }

    void makeFarmLand(unsigned int width, unsigned int height)
    {
        int x = 600;
        int y = 200;
        for (unsigned int i = 0; i < height; i++)
        {
            for (unsigned int j = 0; j < width; j++)
            {
                objects.insert(objects.begin() + 1, std::shared_ptr<drawable>(new dirt{sf::Vector2f(x, y), clock, corn}));
                farmland.push_back(dynamic_cast<dirt *>(objects[1].get()));
                x += 32;
            }
            x = 600;
            y += 32;
        }
    }
};

#endif // V2CPSE2_EXAMPLES_GAMECONTROL_HPP
