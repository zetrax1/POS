
#include "StrelecView.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>


namespace view
{



Strelec_view::Strelec_view()
{

}

Strelec_view::~Strelec_view()
{


}

sf::Texture& Strelec_view::getTexture() 
{
    return m_textura;
}

void Strelec_view::setTexture() 
{
    if (!m_textura.loadFromFile("sfml-icon-small.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
    }
    m_textura.setSmooth(true);

}



void Strelec_view::readTextura(sf::Texture &textura) 
{
    if (!textura.loadFromFile("sfml-icon-small.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
    }
    textura.setSmooth(true);
    
}

}