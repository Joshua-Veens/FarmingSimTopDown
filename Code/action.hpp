//
// Created by joshu on 19-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_ACTION_HPP
#define V2CPSE2_EXAMPLES_ACTION_HPP

#include <iostream>
#include <functional>
#include "SFML/Graphics.hpp"

class action {
private:
    std::function< bool() > condition;
    std::function< void() > work;
    bool busy = false;
public:

    action(
            std::function< bool() > condition,
            std::function< void() > work
    ) : condition( condition ),
        work( work )
    {}

    action(
            sf::Keyboard::Key key,
            std::function< void() > work
    ) :
            condition(
                    [ key , this]()->bool { return sf::Keyboard::isKeyPressed( key ) && !busy; }
            ),
            work(work)
    {}

    action(
            sf::Keyboard::Key key1,
            sf::Keyboard::Key key2,
            std::function<void()> work
    ) :
            condition(
                    [ key1, key2 , this]() -> bool { return sf::Keyboard::isKeyPressed(key1) && sf::Keyboard::isKeyPressed(key2) && !busy; }
            ),
            work(work)
    {}

    action(
            sf::Mouse::Button button,
            std::function< void() > work
    ) :
            condition(
                    [ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
            ),
            work(work)
    {}

    action(
            std::function< void() > work
    ) :
            condition(
                    []()->bool { return true; }
            ),
            work(work)
    {}

    void operator()(){
        if( condition() ){
            busy = true;
            work();
        }
    }

    void setBusy(bool running){
        busy = running;
    }

};



#endif //V2CPSE2_EXAMPLES_ACTION_HPP
