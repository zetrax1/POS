
#include "strelec_view.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>


namespace view
{



Strelec_view::Strelec_view(/* args */)
{
    if (!textura.loadFromFile("sfml-icon-small.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
    }
    textura.setSmooth(true);

}

Strelec_view::~Strelec_view()
{


}

sf::Texture Strelec_view::getTexture() 
{
    return textura;
}

}