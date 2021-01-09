#ifndef MAPA_H
#define MAPA_H

#include <SFML/Graphics.hpp>

namespace model
{

class Mapa
{
private:
    /* data */
public:
    Mapa(/* args */);
    ~Mapa();

    Mapa &operator=(Mapa &x);
    sf::Texture getTexture();
};

}

#endif