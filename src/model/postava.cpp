#include "postava.hpp"
#include "strelec.hpp"
#include <memory>

namespace model
{


Postava::Postava() :  m_strelec(std::make_shared<Strelec>()),
    m_pozicia(0,0)
{    
    setSprite();
    m_sprite.setPosition(0,0);
}

Postava::~Postava()
{
}

std::shared_ptr<Strelec> Postava::getStrelec() 
{
    return m_strelec;
}


void Postava::pohyb_na_mape()
{
        
}

std::pair<int,int> Postava::getPozicia()  
{
    return m_pozicia;
}

void Postava::setPozicia(int x,int y) 
{
    m_pozicia.first = x;
    m_pozicia.second = y;
    m_sprite.setPosition(x,y);
}

void Postava::setSprite() 
{
    m_strelec->getView().readTextura(m_texture);
    m_sprite.setTexture(m_texture);
    sf::FloatRect spriteSize=m_sprite.getGlobalBounds();
    m_sprite.setOrigin(spriteSize.width/2.,spriteSize.height/2.);
}

sf::Sprite Postava::getSprite() 
{
    return m_sprite;
}

}