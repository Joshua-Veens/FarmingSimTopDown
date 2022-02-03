#include "dirt.hpp"


dirt::dirt(sf::Vector2f position, sf::Clock & clock):
    position(position),
    clock(clock),
    collider(position.x+14, position.y + 14, 4,4)
{
    image.loadFromFile(crops[active_type][cropcounter]);
    texture.loadFromImage(image);
}

type dirt::getActiveType() {
    return active_type;
}

void dirt::seed()
{
    if (state == unseeded && active_own == owned)
    {
        state = seeded;
        cropcounter++;
        image.loadFromFile(crops[active_type][cropcounter]);
        texture.loadFromImage(image);
        sf::Time time = clock.getElapsedTime();
        int64_t elpasedTime = time.asMicroseconds();
        particles.generate(sf::Vector2i (position.x+5,position.y-5), elpasedTime, {128, 55, 15}, sf::Vector2f(6,6));
    }
}

void dirt::update()
{
    if (ticks == wait_time && state == seeded)
    {
        ticks = 0;
        state = growingStage1;
        cropcounter++;
        image.loadFromFile(crops[active_type][cropcounter]);
        texture.loadFromImage(image);
    }
    else if (ticks == wait_time && state == growingStage1)
    {
        ticks = 0;
        state = growingStage2;
        cropcounter++;
        image.loadFromFile(crops[active_type][cropcounter]);
        texture.loadFromImage(image);
    }
    else if (ticks == wait_time && state == growingStage2)
    {
        ticks = 0;
        state = growingStage3;
        cropcounter++;
        image.loadFromFile(crops[active_type][cropcounter]);
        texture.loadFromImage(image);
    }
    else if (ticks == wait_time && state == growingStage3)
    {
        ticks = 0;
        state = growingStage4;
        cropcounter++;
        image.loadFromFile(crops[active_type][cropcounter]);
        texture.loadFromImage(image);
    }
    else if (ticks == wait_time && state == growingStage4)
    {
        ticks = 0;
        state = grown;
        cropcounter++;
        image.loadFromFile(crops[active_type][cropcounter]);
        texture.loadFromImage(image);
    }
    else if (state == seeded || state == growingStage1 || state == growingStage2 || state == growingStage3 || state == growingStage4 || state == grown)
    {
        ticks += 1;
    }
}

bool dirt::harvest()
{
    if (state == grown)
    {
        state = unseeded;
        cropcounter = 0;
        image.loadFromFile(crops[active_type][cropcounter]);
        texture.loadFromImage(image);
        sf::Time time = clock.getElapsedTime();
        int64_t elpasedTime = time.asMicroseconds();
        particles.generate(sf::Vector2i (position.x+5,position.y-5), elpasedTime, {237, 193, 33, 150}, sf::Vector2f(4,4));
        ticks = 0;
        return true;
    }
    return false;
}


void dirt::draw(sf::RenderWindow &window)
{
    sprite.setTexture(texture, true);
    sprite.setPosition(position);
    window.draw(sprite);
    particles.updatePool(window);
}

sf::FloatRect dirt::getBounds(){
    return collider;
}

void dirt::changeToWheat(){
    this->active_type = wheat;
}

void dirt::changeToCorn(){
    this->active_type = corn;
}

void dirt::changeToWeed() {
    this->active_type = weed;
}

dirt::state_t dirt::getState() {
    return this->state;
}

void dirt::setToOwned() {
    this->active_own = owned;
}

bool dirt::getOwned() {
    if(active_own == 0) {
        return true;
    }else{
        return false;
    }
} 

void dirt::setPosition(sf::Vector2f newPos){
    position = newPos;
}

void dirt::setState(state_t newState){
    state = newState;
}
