
#include "main.h"


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Peut-être en faire plusieurs pour faire Zbuffer
    sf::RenderTexture renderTexture;
    
    if (!renderTexture.create(800, 600))
    {
        // erreur...
    }

    const sf::Texture& texture_aff = renderTexture.getTexture();
    sf::Sprite sprite_fenetre(texture_aff);
    
    sf::CircleShape shape(100.f,100);
    shape.setFillColor(sf::Color::Green);


    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "key " << event.key.code <<" was pressed" << std::endl;
                std::cout << "control:" << event.key.control << std::endl;
                std::cout << "alt:" << event.key.alt << std::endl;
                std::cout << "shift:" << event.key.shift << std::endl;
                std::cout << "system:" << event.key.system << std::endl;
            }

            if (event.key.code == sf::Keyboard::Escape)
            {
                std::cout << "the escape key was pressed" << std::endl;
                std::cout << "control:" << event.key.control << std::endl;
                std::cout << "alt:" << event.key.alt << std::endl;
                std::cout << "shift:" << event.key.shift << std::endl;
                std::cout << "system:" << event.key.system << std::endl;
                window.close();
            }

            if (event.type == sf::Event::JoystickConnected)
                std::cout << "joystick connected: " << event.joystickConnect.joystickId << std::endl;
            if (event.type == sf::Event::JoystickDisconnected)
                std::cout << "joystick disconnected: " << event.joystickConnect.joystickId << std::endl;
        }

        window.clear();

        renderTexture.clear(sf::Color::Cyan);
        renderTexture.draw(shape);
        renderTexture.display();
        
        shape.move(sf::Vector2f(0.0005 * elapsed.asMicroseconds(), 0.0003 * elapsed.asMicroseconds()));


        window.draw(sprite_fenetre);

        window.display();

    }
      
   
    return 0;
}