#ifndef V2CPSE2_EXAMPLES_GAMECONTROL_HPP
#define V2CPSE2_EXAMPLES_GAMECONTROL_HPP

#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
#include "saveHouse.hpp"
#include "inventory.hpp"
#include "marketplace.hpp"
#include "switchMenu.hpp"
#include "saver.hpp"
#include "loader.hpp"
#include "shop.hpp"
#include "tree.hpp"
#include "vehicle_shop.hpp"
#include "map.hpp"

/// \brief Gamecontrol Class
/// \details This is the class that runs the game. Here all drawable are created and drawn in a loop.

class gameControl
{
private:
    bool speedhacks = false;
    sf::RenderWindow window{sf::VideoMode{1920, 1080}, "SFML window"};
    bool busy = false;
    sf::Clock clock;
    sf::Clock updateClock;
    sf::View view = window.getView();
    sf::Time updateTime = sf::seconds(1.f/60.f);
    sf::Music harvesterSound;
    sf::Music harvesterStartUpSound;
    sf::Music tractorSound;
    sf::Music tractorStartUpSound;
    bool tractorStarted = false;
    bool harvesterStarted = false;

    std::vector<dirt *> farmlandMiddle{};
    std::vector<dirt *> farmlandLeft{};
    std::vector<dirt *> farmlandRight{};
    std::vector<dirt *> farmlandTop{};
    std::vector<dirt *> farmlandBottom{};
    std::vector<dirt *> farmlandTopRight{};
    std::vector<std::vector<dirt *>> farmlands{farmlandMiddle,farmlandLeft,farmlandRight,farmlandTop,farmlandBottom,farmlandTopRight};
    std::vector<std::shared_ptr<drawable>> objects = {
        std::shared_ptr<drawable>(new picture{"images\\topdownfarming_background.png", sf::Vector2f(-1920, -1080)}),
        std::shared_ptr<drawable>(new inventory{sf::Vector2f(222, 300)}),
        std::shared_ptr<drawable>(new marketplace{sf::Vector2f(3160, 300)}),
        std::shared_ptr<drawable>(new vehicle_shop{sf::Vector2f(3050, -957),clock}),
        std::shared_ptr<drawable>(new tractor{sf::Vector2f(200, 240)}),
        std::shared_ptr<drawable>(new harvester{sf::Vector2f(200, 240)}),
        std::shared_ptr<drawable>(new farmhouse{sf::Vector2f(10, 320)}),
        std::shared_ptr<drawable>(new saveHouse{sf::Vector2f(2350, 1343)})
    };

    inventory *silo = dynamic_cast<inventory *>(objects[1].get());
    marketplace *market = dynamic_cast<marketplace *>(objects[2].get());
    vehicle_shop *vehicleShop = dynamic_cast<vehicle_shop *>(objects[3].get());
    tractor *trekker = dynamic_cast<tractor *>(objects[4].get());
    harvester *combine = dynamic_cast<harvester *>(objects[5].get());
    farmhouse *barn = dynamic_cast<farmhouse *>(objects[6].get());
    saveHouse *saveHome = dynamic_cast<saveHouse *>(objects[7].get());
    shop winkel = shop(farmlands, market, clock);
    std::array<vehicle *, 2> vehicles = {trekker, combine};

    player Player = player(vehicles);
    player *pPlayer = &Player;
    saver save = saver(Player, farmlands, silo, market,combine,trekker,vehicleShop);

    menu Menu = menu(window, save);
    pause_menu pMenu = pause_menu(window, save);
    map worldmap = map(window, save);


    switchMenu sMenu = switchMenu(window, save, pPlayer);
    std::vector<drawable *> drawables = {barn, saveHome, market, silo, vehicleShop,};
  
    action actions[13] = {
            action(sf::Keyboard::W, [&]()
            { movement(sf::Vector2f(0.0, -2.0), 0); }),
            action(sf::Keyboard::S, [&]()
            { movement(sf::Vector2f(0.0, +2.0), 180); }),
            action(sf::Keyboard::A, [&]()
            { movement(sf::Vector2f(-2.0, 0.0), 270); }),
            action(sf::Keyboard::D, [&]()
            { movement(sf::Vector2f(+2.0, 0.0), 90); }),

            action(sf::Keyboard::Num1, [&]()
            { pPlayer->getVehicle()->changeToNormal(); }),
            action(sf::Keyboard::Num2, [&]()
            { pPlayer->getVehicle()->changeToAction(); }),
            action(sf::Keyboard::Num3, [&]()
            { pPlayer->getVehicle()->changeToTrailer(); }),
            action(sf::Keyboard::R, [&]()
            { sMenu.show(), tractorStarted = false, harvesterStarted = false; }),

            action(sf::Keyboard::V, [&]()
            { trekker->setCrop(clock); }),

            action(sf::Mouse::Button::Left, [&]()
            { winkel.buyLand(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window))), window); }),

            action(sf::Keyboard::P, [&]()
            { SPEEEDDD(); }),

            action(sf::Keyboard::M, [&]()
            { worldmap.show("images\\map.png"); }),

            action(sf::Keyboard::Escape, [this]{
                if(Menu.getActive() || pMenu.getActive()){
                    return;
                }pMenu.show(); })
    };

    void SPEEEDDD();

    void input();

    void render();

    void renderRest();

    void movement(sf::Vector2f speed, int rotation);

    void playSound();

    void makeFarmLand(sf::Vector2f position, unsigned int width, unsigned int height, unsigned int index);

    void makeTrees(sf::Vector2f position, unsigned int amount, bool vertical = false);

    void changeLocation(sf::Vector2f windowsize);

public:
    ///@brief runs the game.
    void runGame();



   void runGame();
};

#endif // V2CPSE2_EXAMPLES_GAMECONTROL_HPP
