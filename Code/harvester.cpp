#include "harvester.hpp"

harvester::harvester(sf::Vector2f position) :
        vehicle(position),
        collider(position.x - 40, position.y - 42, 80, 20),
        blokje(sf::Vector2f(position.x-40,position.y-42), sf::Vector2f(80, 20))
{image.loadFromFile("images\\harvester_closed.png");}

void harvester::draw(sf::RenderWindow &window) {
    this->updateCollider();
    sprite.setTexture(image);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2f(64,64));
    window.draw(sprite);
    blokje.draw(window);
}

void harvester::move(sf::Vector2f delta, std::vector<drawable *> objects) {
    for(unsigned int i = 0; i < objects[0]->getColliders().size(); i++){
        if(objects[0]->getColliders()[i].intersects(collider)){
            return;
        }
    }
    if(objects[1]->getCollider().intersects(collider)){
        return;
    }
    if(objects[0]->getCollider().intersects(collider)){
//       SPECIAAL PLEKJE VOOR ERIK ZIJN CODE & DINGEN
    }
    if(active_type == 0){
        position += sf::Vector2f(delta.x/2, delta.y/2);
    }else if(active_type == 1){
        position += sf::Vector2f(delta.x, delta.y);
    }
}

void harvester::update(std::vector<dirt *> farmland){
    for(auto & p : farmland){
        if(p->getBounds().intersects(collider) && active_type == 1){
            p->harvest();
        }
    }
}

void harvester::setRotation( int rotation ) {
    sprite.setRotation(rotation);
    savedRotation = rotation;
}

void harvester::changeToNormal(){
    image.loadFromFile("images\\harvester_closed.png");
    active_type = notHarvesting;
}

void harvester::changeToAction(){
    image.loadFromFile("images\\harvester.png");
    active_type = harvesting;
}

void harvester::updateCollider(){
    if(savedRotation == 0){
        collider.left = position.x - 40;
        collider.top = position.y - 42;
        collider.height = 20;
        collider.width = 80;
        blokje.jump(sf::Vector2f(position.x-40, position.y-42));
        blokje.setSize(sf::Vector2f(80, 20));
    }
    else if(savedRotation == 180){
        collider.left = position.x - 40;
        collider.top = position.y + 22;
        collider.height = 20;
        collider.width = 80;
        blokje.jump(sf::Vector2f(position.x-40, position.y+22));
        blokje.setSize(sf::Vector2f(80, 20));
    }
    else if(savedRotation == 270){
        collider.left = position.x - 42;
        collider.top = position.y - 40;
        collider.height = 80;
        collider.width = 20;
        blokje.jump(sf::Vector2f(position.x-42, position.y-40));
        blokje.setSize(sf::Vector2f(20, 80));
    }
    else if(savedRotation == 90){
        collider.left = position.x + 22;
        collider.top = position.y - 40;
        collider.height = 80;
        collider.width = 20;
        blokje.jump(sf::Vector2f(position.x+22, position.y-40));
        blokje.setSize(sf::Vector2f(20, 80));
    }
}

int harvester::getRotation() {
    return savedRotation;
}

sf::Vector2f harvester::getPosition() {
    return position;
}