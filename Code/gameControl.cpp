//
// Created by joshu on 19-1-2022.
//

#include "gameControl.hpp"

void gameControl::runGame()
{
    objects.insert(objects.begin()+8,std::shared_ptr<drawable>(new picture{"images\\splash.png", sf::Vector2f(0,0)}));
    render();
    window.display();
    sf::sleep(sf::milliseconds(2000));
    objects.erase(objects.begin()+8);

    tractorSound.openFromFile("audio\\JohnDeer.ogg");
    tractorStartUpSound.openFromFile("audio\\TractorStarting.ogg");
    harvesterSound.openFromFile("audio\\Harvesting.ogg");
    harvesterStartUpSound.openFromFile("audio\\HarvesterStarting.ogg");
    harvesterSound.setVolume(10);
    harvesterStartUpSound.setVolume(50);
    tractorSound.setVolume(40);
    tractorStartUpSound.setVolume(60);

    loader Loader;

    pPlayer = Loader.loadPlayerAndMoney(pPlayer,market);
    silo = Loader.loadSilo(silo);

    sf::Music music;
    if(!music.openFromFile("audio\\backgroundmusic.ogg")){
        std::cout << "Cant load audio\n";
    }
    music.play();
    music.setLoop(true);
    music.setVolume(75);

    makeTrees(sf::Vector2f(-130, 625), 13);
    makeTrees(sf::Vector2f(1310, 743), 5, true);
    makeTrees(sf::Vector2f(-130, 1330), 13);
    makeTrees(sf::Vector2f(-650, 1530), 14);
    makeTrees(sf::Vector2f(0, 55), 4);
    makeTrees(sf::Vector2f(-130, 625), 13);
    makeTrees(sf::Vector2f(-1150, -325), 16);
    makeTrees(sf::Vector2f(3070, -390), 5);
    makeTrees(sf::Vector2f(3710, -1030), 6, true);
    makeTrees(sf::Vector2f(3710, -1030), 6, true);
    makeTrees(sf::Vector2f(3060, 57), 5);
    makeTrees(sf::Vector2f(3060, 630), 6);
    makeTrees(sf::Vector2f(3060, 750), 5, true);

    makeFarmLand(sf::Vector2f(532, 40), 40, 16, 0);     //Middle
    makeFarmLand(sf::Vector2f(-1600, 340), 40, 34, 1);  //Left
    makeFarmLand(sf::Vector2f(2200, 340), 22, 20, 2);   //Right
    makeFarmLand(sf::Vector2f(-1850, -1000), 80, 20, 3);   //Top
    makeFarmLand(sf::Vector2f(2220, -1000), 22, 35, 4);   //TopRight

    farmlands = Loader.loadFarms(farmlands);

    if (window.isOpen())
    {
        Menu.show();
    }

    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        timeSinceLastUpdate += updateClock.restart();
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
            windowsize = (sf::Vector2f)window.getSize();
            changeLocation(windowsize);
            window.setView(view);
        }

        render();
        renderRest();

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

void gameControl::SPEEEDDD()
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
            updateTime = sf::milliseconds(4);
            speedhacks = true;
        }
    }
}

void gameControl::input()
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

void gameControl::render()
{
    window.clear();

    for (auto &object : objects)
    {
        object->draw(window);
    }
}

void gameControl::renderRest(){
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
    }
    else if (pPlayer->getVehicle() == trekker && trekker->getActiveType() == 1)
    {
        trekker->drawWhatSeeding(window, sf::Vector2f((viewingpoint.x - windowsize.x/2), (viewingpoint.y - windowsize.y/2)));
    }
    trekker->depositCrop(window, silo);
    trekker->sellCrops(window, market);
    silo->drawInventory(window);
    market->drawMoney(window, sf::Vector2f((viewingpoint.x - windowsize.x/2), (viewingpoint.y - windowsize.y/2)));
    vehicleShop->buyVehicle(window, trekker, combine, market);
    window.display();
}

void gameControl::movement(sf::Vector2f speed, int rotation)
{
    playSound();
    pPlayer->getVehicle()->move(speed, drawables);
    pPlayer->getVehicle()->setRotation(rotation);
    if (pPlayer->getVehicle()->getCollider().intersects(barn->getCollider()))
    {
        sMenu.show();
    }
}

void gameControl::playSound(){
    if(pPlayer->getVehicle() == combine){
        if(!harvesterStarted){
            harvesterSound.stop();
            harvesterStarted = true;
            harvesterStartUpSound.play();
        }if(harvesterStartUpSound.getStatus() == sf::SoundSource::Playing) {
        }else{
            if (harvesterSound.getStatus() == sf::SoundSource::Playing) {
            } else {
                tractorSound.stop();
                harvesterSound.play();
                harvesterSound.setLoop(true);
            }
        }
    }
    if(pPlayer->getVehicle() == trekker){
        if(!tractorStarted){
            tractorSound.stop();
            tractorStarted = true;
            tractorStartUpSound.play();
        }if(tractorStartUpSound.getStatus() == sf::SoundSource::Playing) {
        }else {
            if (tractorSound.getStatus() == sf::SoundSource::Playing) {
            } else {
                harvesterSound.stop();
                tractorSound.play();
                tractorSound.setLoop(true);
            }
        }
    }
}

void gameControl::makeFarmLand(sf::Vector2f position, unsigned int width, unsigned int height, unsigned int index)
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


void gameControl::makeTrees(sf::Vector2f position, unsigned int amount, bool vertical){
    if(vertical){
        for(unsigned int i = 0; i < amount; i++){
            objects.push_back(std::shared_ptr<drawable>(new tree{position, rand() % 3}));
            drawables.push_back(dynamic_cast<tree *>(objects[objects.size()-1].get()));
            position.y += 120;
        }
    }else{
        for(unsigned int i = 0; i < amount; i++){
            objects.push_back(std::shared_ptr<drawable>(new tree{position, rand() % 3}));
            drawables.push_back(dynamic_cast<tree *>(objects[objects.size()-1].get()));
            position.x += 120;
        }
    }
}

void gameControl::changeLocation(sf::Vector2f windowsize)
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