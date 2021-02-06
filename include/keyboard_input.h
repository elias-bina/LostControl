#ifndef _KEYBOARD_INPUT_

#define _KEYBOARD_INPUT_

#include <iostream>
#include <fstream>
#include <string>

#include "input.h"

class KeyboardInput : public Input{
    public:
        KeyboardInput(int player);
        ~KeyboardInput();

        bool getLeft();
        bool getRight();
        bool getAction();

    private:
        int _player;
        sf::Keyboard::Key _left_bind;
        sf::Keyboard::Key _right_bind;
        sf::Keyboard::Key _action_bind;

};


#endif//_KEYBOARD_INPUT_