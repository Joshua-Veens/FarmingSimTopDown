#include "dirt.hpp"
#include "iostream"

dirt::dirt(sf::Vector2f position, sf::Clock & clock, type active_type):
    position(position),
    active_type(active_type),
    clock(clock),
    collider(position.x+14, position.y + 14, 4,4)
{
    image.loadFromFile(crops[active_type][cropcounter]);
    texture.loadFromImage(image);
}

void dirt::seed()
{
    if (state == unseeded)
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
    sprite.setScale(0.25,0.25);
    window.draw(sprite);
    particles.updatePool(window);
}

sf::FloatRect dirt::getBounds(){
    return collider;
}
