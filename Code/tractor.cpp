#include "tractor.hpp"

tractor::tractor( sf::Vector2f position, std::string type):
        position(position),
        type(type),
        seeder_collider(position.x-30, position.y+30, 60, 20),
        tractor_collider(position.x-10, position.y-36, 20, 5),
        blokje(sf::Vector2f(position.x-10,position.y-36), sf::Vector2f(20, 5))
{}

void tractor::draw(sf::RenderWindow &window) {
    this->updateCollider();
    image.loadFromFile(filename);
    sprite.setTexture(image);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2f(64,64));
    window.draw(sprite);
    blokje.draw(window);
}

void tractor::move(sf::Vector2f delta, drawable *object) {
    for(unsigned int i = 0; i < object->getColliders().size(); i++){
        if(object->getColliders()[i].intersects(tractor_collider)){
            return;
        }
    }
    if(object->getCollider().intersects(tractor_collider)){
//       SPECIAAL PLEKJE VOOR ERIK ZIJN CODE & DINGEN
    }
    if(type == "seeder"){
        position += sf::Vector2f(delta.x/1.5, delta.y/1.5);
    }else if(type == "trekker"){
        position += sf::Vector2f(delta.x*2, delta.y*2);
    }
}

void tractor::update(std::vector<dirt *> farmland){
    for(auto & p : farmland){
        if(p->getBounds().intersects(seeder_collider) && type == "seeder"){
            p->seed();
        }
        p->update();
    }
}

void tractor::setRotation( int rotation ) {
    sprite.setRotation(rotation);
    savedRotation = rotation;
}

void tractor::changeToNormal(){
    filename = "images\\trekkerjurgen.png";
    type = "trekker";
}

void tractor::changeToAction(){
    filename = "images\\trekkerseeder.png";
    type = "seeder";
}

void tractor::updateCollider(){
    if(savedRotation == 0){
        seeder_collider.left = position.x - 30;
        seeder_collider.top = position.y + 30;
        seeder_collider.height = 20;
        seeder_collider.width = 60;

        tractor_collider.left = position.x - 10;
        tractor_collider.top = position.y - 36;
        tractor_collider.height = 5;
        tractor_collider.width = 20;
        blokje.jump(sf::Vector2f(position.x-10, position.y - 36));
        blokje.setSize(sf::Vector2f(20, 5));
    }
    else if(savedRotation == 180){
        seeder_collider.left = position.x - 30;
        seeder_collider.top = position.y - 50;
        seeder_collider.height = 20;
        seeder_collider.width = 60;

        tractor_collider.left = position.x - 10;
        tractor_collider.top = position.y + 36;
        tractor_collider.height = 5;
        tractor_collider.width = 20;
        blokje.jump(sf::Vector2f(position.x-10, position.y+32));
        blokje.setSize(sf::Vector2f(20, 5));
    }
    else if(savedRotation == 270){
        seeder_collider.left = position.x + 30;
        seeder_collider.top = position.y - 30;
        seeder_collider.height = 60;
        seeder_collider.width = 20;

        tractor_collider.left = position.x - 35;
        tractor_collider.top = position.y - 10;
        tractor_collider.height = 20;
        tractor_collider.width = 5;
        blokje.jump(sf::Vector2f(position.x - 35, position.y - 10));
        blokje.setSize(sf::Vector2f(5, 20));
    }
    else if(savedRotation == 90){
        seeder_collider.left = position.x - 50;
        seeder_collider.top = position.y - 30;
        seeder_collider.height = 60;
        seeder_collider.width = 20;

        tractor_collider.left = position.x + 32;
        tractor_collider.top = position.y - 10;
        tractor_collider.height = 20;
        tractor_collider.width = 5;
        blokje.jump(sf::Vector2f(position.x + 32, position.y - 10));
        blokje.setSize(sf::Vector2f(5, 20));
    }
}

int tractor::getRotation() {
    return savedRotation;
}

sf::Vector2f tractor::getPosition() {
    return position;
}

void tractor::setPosition(sf::Vector2f location){
    position = location;
}