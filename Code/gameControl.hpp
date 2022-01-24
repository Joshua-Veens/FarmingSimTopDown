//
// Created by joshu on 19-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_GAMECONTROL_HPP
#define V2CPSE2_EXAMPLES_GAMECONTROL_HPP

#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "picture.hpp"
#include "action.hpp"
#include "dirt.hpp"
#include "tractor.hpp"
#include "farmhouse.hpp"
#include "menu.hpp"
#include "pauseMenu.hpp"

class gameControl
{
private:
    sf::RenderWindow window{sf::VideoMode{1920, 1080}, "SFML window"};
    bool busy = false;
    //    sf::Time elapsedTime, updateTime = sf::milliseconds(20);
    //    sf::Clock clock;
    menu Menu = menu(window);
    pause_menu pMenu = pause_menu(window);
    std::vector<std::shared_ptr<drawable>> objects = {
        std::shared_ptr<drawable>(new picture{"level_1.png", sf::Vector2f(0, 0)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(600, 200)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(728, 200)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(856, 200)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(600, 328)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(728, 328)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(856, 328)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(600, 456)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(728, 456)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(856, 456)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(600, 584)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(728, 584)}),
        std::shared_ptr<drawable>(new dirt{sf::Vector2f(856, 584)}),
        std::shared_ptr<drawable>(new tractor{sf::Vector2f(200, 200), "trekker"}),
        std::shared_ptr<drawable>(new farmhouse{sf::Vector2f(100, 450)})};

    tractor *trekker = dynamic_cast<tractor *>(objects[13].get());

    std::array<dirt *, 12> farmland = {dynamic_cast<dirt *>(objects[1].get()),
                                       dynamic_cast<dirt *>(objects[2].get()),
                                       dynamic_cast<dirt *>(objects[3].get()),
                                       dynamic_cast<dirt *>(objects[4].get()),
                                       dynamic_cast<dirt *>(objects[5].get()),
                                       dynamic_cast<dirt *>(objects[6].get()),
                                       dynamic_cast<dirt *>(objects[7].get()),
                                       dynamic_cast<dirt *>(objects[8].get()),
                                       dynamic_cast<dirt *>(objects[9].get()),
                                       dynamic_cast<dirt *>(objects[10].get()),
                                       dynamic_cast<dirt *>(objects[11].get()),
                                       dynamic_cast<dirt *>(objects[12].get())};

    action actions[7] = {
        //            action( sf::Keyboard::W, sf::Keyboard::D,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  +1.0, -1.0 )); objectlist["Trekker"].setRotation(45);} ),
        //            action( sf::Keyboard::W, sf::Keyboard::A,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  -1.0, -1.0 )); objectlist["Trekker"].setRotation(315); }),
        //            action( sf::Keyboard::S, sf::Keyboard::D,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  +1.0, +1.0 )); objectlist["Trekker"].setRotation(135); }),
        //            action( sf::Keyboard::S, sf::Keyboard::A,   [&](){ objectlist["Trekker"].move( sf::Vector2f(  -1.0, +1.0 )); objectlist["Trekker"].setRotation(225); }),

        action(sf::Keyboard::W, [&]()
               { trekker->move( sf::Vector2f(  0.0, -4.0 )); trekker->setRotation(0); }),
        action(sf::Keyboard::S, [&]()
               { trekker->move( sf::Vector2f(  0.0, +4.0 )); trekker->setRotation(180); }),
        action(sf::Keyboard::A, [&]()
               { trekker->move( sf::Vector2f( -4.0,  0.0 )); trekker->setRotation(270); }),
        action(sf::Keyboard::D, [&]()
               { trekker->move( sf::Vector2f( +4.0,  0.0 )); trekker->setRotation(90); }),
        action(sf::Keyboard::Num1, [&]()
               { trekker->changeToTractor(); }),
        action(sf::Keyboard::Num2, [&]()
               { trekker->changeToSeeder(); }),
        action(sf::Keyboard::Escape, [this]
               {if(Menu.getActive() || pMenu.getActive()){
                return;
            } pMenu.show(); })};

public:
    void runGame()
    {
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
            trekker->update(farmland);
            render();
            sf::sleep(sf::milliseconds(5));
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
};

#endif // V2CPSE2_EXAMPLES_GAMECONTROL_HPP
