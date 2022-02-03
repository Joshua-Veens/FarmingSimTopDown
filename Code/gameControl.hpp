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

class gameControl
{
private:
    bool speedhacks = false;
    sf::RenderWindow window{sf::VideoMode{1920, 1080}, "SFML window"};
    bool busy = false;
    sf::Clock clock;
    sf::View view = window.getView();
    sf::Time updateTime = sf::seconds(1.f/60.f);
    std::vector<dirt *> farmlandMiddle{};
    std::vector<dirt *> farmlandLeft{};
    std::vector<dirt *> farmlandRight{};
    std::vector<dirt *> farmlandTop{};
    std::vector<dirt *> farmlandBottom{};
    std::vector<dirt *> farmlandLeftTop{};
    std::vector<std::vector<dirt *>> farmlands{farmlandMiddle,farmlandLeft,farmlandRight,farmlandTop,farmlandBottom,farmlandLeftTop};
    
    std::vector<std::shared_ptr<drawable>> objects = {
        std::shared_ptr<drawable>(new picture{"images\\topdownfarming_background.png", sf::Vector2f(-1920, -1080)}),
        std::shared_ptr<drawable>(new inventory{sf::Vector2f(222, 300)}),
        std::shared_ptr<drawable>(new marketplace{sf::Vector2f(3160, 300)}),
        std::shared_ptr<drawable>(new tractor{sf::Vector2f(200, 200)}),
        std::shared_ptr<drawable>(new harvester{sf::Vector2f(200, 200)}),
        std::shared_ptr<drawable>(new farmhouse{sf::Vector2f(10, 320)}),
        std::shared_ptr<drawable>(new saveHouse{sf::Vector2f(900, 750)})
    };

    inventory *silo = dynamic_cast<inventory *>(objects[1].get());
    marketplace *market = dynamic_cast<marketplace *>(objects[2].get());
    tractor *trekker = dynamic_cast<tractor *>(objects[3].get());
    harvester *combine = dynamic_cast<harvester *>(objects[4].get());
    farmhouse *barn = dynamic_cast<farmhouse *>(objects[5].get());
    saveHouse *saveHome = dynamic_cast<saveHouse *>(objects[6].get());
    shop winkel = shop(farmlands, market, clock);

    saver save = saver(Player, farmlands, silo, market);
    menu Menu = menu(window, save);
    pause_menu pMenu = pause_menu(window, save);


    std::array<vehicle *, 2> vehicles = {trekker, combine};
    player Player = player(vehicles);
    player *pPlayer = &Player;
    switchMenu sMenu = switchMenu(window, save, pPlayer);
    std::vector<drawable *> drawables = {barn, saveHome, market, silo};

  
    action actions[12] = {
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
               { sMenu.show(); }),

        action(sf::Keyboard::V, [&]()
                { trekker->setCrop(clock); }),
        
        action(sf::Mouse::Button::Left, [&]()
                { winkel.buyLand(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window))), window); }),

        action(sf::Keyboard::P, [&]()
               { SPEEEDDD(); }),

        action(sf::Keyboard::Escape, [this]{
            if(Menu.getActive() || pMenu.getActive()){
                return;
            }pMenu.show(); })
      };

public:
    void runGame()
    {
        loader Loader;
        pPlayer = Loader.loadPlayerAndMoney(pPlayer, market);

        sf::Music music;
        if(!music.openFromFile("audio\\backgroundmusic.ogg")){
            std::cout << "error\n";
        }
        music.play();
        music.setLoop(true);

        makeTrees(sf::Vector2f(-130, 625), 13);
        makeTrees(sf::Vector2f(1310, 743), 5, true);
        makeTrees(sf::Vector2f(-130, 1330), 13);
        makeTrees(sf::Vector2f(-650, 1530), 14);
        makeTrees(sf::Vector2f(0, 55), 4);
        addTreesToVector();

        makeFarmLand(sf::Vector2f(532, 40), 40, 16, 0);     //Middle
        makeFarmLand(sf::Vector2f(-1600, 340), 40, 34, 1);  //Left
        makeFarmLand(sf::Vector2f(2200, 340), 22, 20, 2);   //Right
        makeFarmLand(sf::Vector2f(-1850, -1000), 80, 20, 3);   //Top

        if (window.isOpen())
        {
            Menu.show();
        }
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while (window.isOpen())
        {
            timeSinceLastUpdate += clock.restart();
            sf::Vector2f windowsize = (sf::Vector2f)window.getSize();

            while (timeSinceLastUpdate > updateTime)
            {
                timeSinceLastUpdate -= updateTime;

                input();
                changeLocation(windowsize);
                window.setView(view);

                trekker->update(farmlands);
                combine->update(farmlands);
                trekker->overloadCrop(combine);

            }

            render();




            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    save.save("save.txt");
                }
                if (event.type == sf::Event::Resized)
                {
                    view.setSize(event.size.width, event.size.height);
                    window.setView(view);
                }
                if (event.type == sf::Event::Resized)
                {
                    view.setSize(event.size.width, event.size.height);
                    window.setView(view);
                }
            }
        }
    }

    void SPEEEDDD()
    {
        sf::Time time = clock.getElapsedTime();
        clock.restart();
        if (time.asMilliseconds() > 500)
        {
            if (speedhacks)
            {
                updateTime = sf::seconds(1.f/60.f);
                speedhacks = false;
            }
            else
            {
                updateTime = sf::milliseconds(1);
                speedhacks = true;
            }
        }
    }

    void input()
    {
        for (auto &action : actions)
        {
            action.setBusy(busy);
        }
        for (auto &action : actions)
        {
            action();
        }
    }

    void render()
    {
        window.clear();
        for (auto &object : objects)
        {
            object->draw(window);
        }
        sf::Vector2f windowsize = sf::Vector2f (window.getSize());
        sf::Vector2f viewingpoint = sf::Vector2f (view.getCenter());
        winkel.draw(window);
        silo->drawSilo(window);
        if (pPlayer->getVehicle() == combine)
        {
            combine->showCropAmount(window, sf::Vector2f((viewingpoint.x - windowsize.x/2), (viewingpoint.y - windowsize.y/2)));
        }

        if (pPlayer->getVehicle() == trekker && trekker->getActiveType() == 2)
        {
            trekker->showCropAmount(window, sf::Vector2f((viewingpoint.x - windowsize.x/2), (viewingpoint.y - windowsize.y/2)));

        }else if (pPlayer->getVehicle() == trekker && trekker->getActiveType() == 1)
        {
            trekker->drawWhatSeeding(window, sf::Vector2f((viewingpoint.x - windowsize.x/2), (viewingpoint.y - windowsize.y/2)));
        }
        trekker->depositCrop(window, silo);
        trekker->sellCrops(window, market);
        silo->drawInventory(window);
        market->drawMoney(window, sf::Vector2f((viewingpoint.x - windowsize.x/2), (viewingpoint.y - windowsize.y/2)));
        window.display();
    }

    void movement(sf::Vector2f speed, int rotation)
    {
        pPlayer->getVehicle()->move(speed, drawables);
        pPlayer->getVehicle()->setRotation(rotation);
        if (pPlayer->getVehicle()->getCollider().intersects(barn->getCollider()))
        {
            sMenu.show();
        }
    }

    void makeFarmLand(sf::Vector2f position, unsigned int width, unsigned int height, unsigned int index)
    {
        winkel.addForSaleSign(sf::Vector2f(position.x-96, position.y-64));
        int x = position.x;
        for (unsigned int i = 0; i < height; i++)
        {
            for (unsigned int j = 0; j < width; j++)
            {
                objects.insert(objects.begin() + 1, std::shared_ptr<drawable>(new dirt{position, clock}));
                farmlands[index].push_back(dynamic_cast<dirt *>(objects[1].get()));
                position.x += 32;
            }
            position.x = x;
            position.y += 32;
        }
    }

    void makeTrees(sf::Vector2f position, unsigned int amount, bool vertical = false){
        if(vertical){
            for(unsigned int i = 0; i < amount; i++){
                objects.push_back(std::shared_ptr<drawable>(new tree{position, rand() % 3}));
                position.y += 120;
            }
        }else{
            for(unsigned int i = 0; i < amount; i++){
                objects.push_back(std::shared_ptr<drawable>(new tree{position, rand() % 3}));
                position.x += 120;
            }
        }
    }

    void addTreesToVector(){
        for(unsigned int i = 7; i < objects.size(); i++){
            drawables.push_back(dynamic_cast<tree *>(objects[i].get()));
        }
    }

    void changeLocation(sf::Vector2f windowsize)
    {
        if (!Menu.getActive())
        {

            sf::Vector2f playerpos = pPlayer->getVehicle()->getPosition();
            int x, y;
            if (playerpos.x < 0)
            {
                x = -windowsize.x * 0.5;
            }
            else if (playerpos.x > windowsize.x)
            {
                x = windowsize.x * 1.5;
            }
            else
            {
                x = windowsize.x * 0.5;
            }
            if (playerpos.y < 0)
            {
                y = -windowsize.y * 0.5;
            }
            else if (playerpos.y > windowsize.y)
            {
                y = windowsize.y * 1.5;
            }
            else
            {
                y = windowsize.y * 0.5;
            }
            view.setCenter(x, y);
        }
    }
};

#endif // V2CPSE2_EXAMPLES_GAMECONTROL_HPP
