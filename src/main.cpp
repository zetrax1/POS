#include <iostream>
#include <functional>
#include "communication/Client.hpp"
#include "communication/Server.hpp"
#include "communication/Data.hpp"
#include "controller/Hra.hpp"
#include "controller/ControllerServer.hpp"
#include "model/Postava.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp)
{
    if (sprite.contains(mp))
    {
        return true;
    }
    return false;
}

int menu()
{
    int retValue = 0;
    sf::RenderWindow window;
    window.create(sf::VideoMode(600, 350), "menu!");

    sf::Texture texture;
    if (!texture.loadFromFile("UvodTexture.png"))
    {
        return 0;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Vector2f mp;
    mp.x = sf::Mouse::getPosition(window).x;
    mp.y = sf::Mouse::getPosition(window).y;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.mouseButton.y < 175)
            {
                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                {

                    window.close();
                    retValue = 1;
                }
            }
            else
            {
                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                {

                    window.close();
                    retValue = 2;
                }
            }
        }
        window.clear(sf::Color::White);
        sprite.setPosition(sf::Vector2f(0, 0));
        window.draw(sprite);

        window.display();
    }
    return retValue;
}

int main(int argc, char **argv)
{

    if (argc == 1)
    {
        int i = menu();
        if (i == 0)
        {
            return 0;
        }
        if (i == 1)
        {
            std::system("./sfml c");
        }
        else
        {
            std::system("./sfml s");
            //std::system("./sfml c");
        }
    }
    if (argc == 2)
    {

        if (argv[1][0] == 's')
        {
            std::cout << "Server";

            // communication::Server server;
            // //std::pair<Data, int> data = server.getFromReadQueu();
            // while (true)
            // {
            // }

            controler::ControllerServer conServ;
            conServ.init();

        }
        if (argv[1][0] == 'c')
        {
            controler::Hra hra;
            model::Postava postava;
            postava.setPozicia(50, 100);
            hra.addNewPostava(postava);
            hra.init_hra();
        }
    }

    return 0;
}
//std::this_thread::sleep_for(std::chrono::nanoseconds(10));