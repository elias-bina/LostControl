
#include "main.h"
#include "utils.h"
#include "rail.h"
#include "reader.h"

int main(int argc, char ** argv)
{

    Path::configure(argv[0]);

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
    r->construct_and_add_shape(& env, Path::getResource("test.txt", ResourceType::LEVEL));

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        window.clear();

        renderTexture.clear(sf::Color::Cyan);

        env.draw_env(renderTexture, window);
        renderTexture.display();

        window.draw(sprite_fenetre);

        window.display();
        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }

            if (event.type == sf::Event::JoystickConnected)
                std::cout << "joystick connected: " << event.joystickConnect.joystickId << std::endl;
            if (event.type == sf::Event::JoystickDisconnected)
                std::cout << "joystick disconnected: " << event.joystickConnect.joystickId << std::endl;
        }

        // Gestion affichage
        
        env.update_env(elapsed);


    }      
   
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