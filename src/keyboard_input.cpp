#include "utils.h"
#include "keyboard_input.h"
#include "Thor/Input.hpp"

KeyboardInput::KeyboardInput(int player) : _player(player){

    std::ifstream infile(Path::getResource("bindings.conf", ResourceType::CONFIG));

    std::string left, right, action;
    int i = 0;
    while (infile >> left >> right >> action)
    {
        if(i == player){

            _left_bind = thor::toKeyboardKey(left);
            _right_bind = thor::toKeyboardKey(right);
            _action_bind = thor::toKeyboardKey(action);
            std::cout << "Bindings for player " << i << " : " << left << ", " << right << " and " << action <<std::endl;
            break;
        }
        i++;
    }
}

KeyboardInput::~KeyboardInput(){
}


bool KeyboardInput::getLeft(){
    return sf::Keyboard::isKeyPressed(_left_bind);
}

bool KeyboardInput::getRight(){
    return sf::Keyboard::isKeyPressed(_right_bind);
}

bool KeyboardInput::getAction(){
    return sf::Keyboard::isKeyPressed(_action_bind);
}