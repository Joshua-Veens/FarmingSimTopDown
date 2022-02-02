#include "gameControl.hpp"

int main() {
    sf::Music music;
    if(!music.openFromFile("audio\\backgroundmusic.ogg")){
        std::cout << "error\n";
    }
    music.play();

    gameControl gameControl;
    gameControl.runGame();

}
