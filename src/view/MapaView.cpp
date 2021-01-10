
#include "MapaView.hpp"

#include <iostream>

namespace view
{



Mapa_view:: Mapa_view(/* args */)
{
}
Mapa_view:: ~Mapa_view()
{
}

void Mapa_view::readTextura(sf::Texture &textura) 
{
    if (!textura.loadFromFile("sfml-icon-small.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
    }
    textura.setSmooth(true);
    
}

}