
#include "main.h"

#include "rail.h"
#include "reader.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    window.setFramerateLimit(60);

    // Peut-être en faire plusieurs pour faire Zbuffer
    sf::RenderTexture renderTexture;
    
    if (!renderTexture.create(800, 600))
    {
        // erreur...
        exit(-1);
    }

    const sf::Texture& texture_aff = renderTexture.getTexture();
    sf::Sprite sprite_fenetre(texture_aff);

    Environnement env;

    Reader* r = new Reader();
    r->construct_and_add_shape(& env, "../test.txt");

    sf::CircleShape shape(100.f,100);
    sf::RectangleShape rect(sf::Vector2f(100,100));
    sf::ConvexShape conv(100);
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    rect.setOrigin(rect.getSize().x / 2,  rect.getSize().y / 2);
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        window.clear();

        renderTexture.clear(sf::Color::Cyan);
        renderTexture.draw(shape);

        env.draw_env(renderTexture, window);
        renderTexture.display();

        window.draw(sprite_fenetre);
        window.draw(rect);


        for (sf::ConvexShape* l : r->getShapes()) {
            int a = (*l).getPoint(1).x;
            l->setFillColor(sf::Color::Red);
            sf::Texture* texture = new sf::Texture();
            texture->loadFromFile("../grass.png");
            l->setTexture(texture);
            window.draw(*l);
        }

        window.display();
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

        // Gestion affichage
        
        env.update_env(elapsed);
        shape.move(sf::Vector2f(0.0005 * elapsed.asMicroseconds(), 0.0003 * elapsed.asMicroseconds()));
        rect.rotate(0.0001 * elapsed.asMicroseconds());
        shape.move(sf::Vector2f(0.00005 * elapsed.asMicroseconds(), 0.00003 * elapsed.asMicroseconds()));


    }

    delete (&renderTexture);
      
   
    return 0;
}

void gestion_clavier()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {

    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {

    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {

    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {

    }

}