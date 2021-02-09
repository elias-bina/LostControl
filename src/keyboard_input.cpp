#include "utils.h"
#include "keyboard_input.h"

KeyboardInput::KeyboardInput(int player) : _player(player){

    std::ifstream infile(Path::getResource("bindings.conf", ResourceType::CONFIG));

    int a, b, c, i=0;
    while (infile >> a >> b >> c)
    {
        if(i == player){
            _left_bind = (sf::Keyboard::Key)a;
            _right_bind = (sf::Keyboard::Key)b;
            _action_bind = (sf::Keyboard::Key)c;
            std::cout << "Bindings for player " << i << " : " << a << ", " << b << " and " << c <<std::endl;
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