#ifndef _INPUT_H_

#define _INPUT_H_

#include <SFML/Graphics.hpp>

class Input{
public:
    Input(/* args */);
    ~Input();

    virtual bool getLeft() = 0;
    virtual bool getRight() = 0;
    virtual bool getAction() = 0;
private:
    /* data */
};


#endif// _INPUT_H_