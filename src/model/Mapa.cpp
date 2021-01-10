#include "Mapa.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace model
{


Mapa::Mapa(/* args */)
{
}

Mapa::~Mapa()
{
}

Mapa& Mapa::operator=(Mapa &x) 
{
    *this = x; 
    return (*this);
}

sf::Texture Mapa::getTexture() 
{
    sf::Texture texture;
    if (!texture.loadFromFile("sfml-icon-small.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
    }
        texture.setSmooth(true);


    return texture;
}

}

