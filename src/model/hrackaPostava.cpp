#include "hrackaPostava.hpp"
#include "strelec.hpp"
#include <memory>

namespace model
{


Postava::Postava() :  m_strelec(std::make_shared<Strelec>()),
    pozicia(0,0)
{
   
    setSprite();

    sprite.setPosition(0,0);
}

Postava::~Postava()
{
}

std::shared_ptr<Strelec> Postava::getStrelec() 
{
    return m_strelec;
}

Strelec Postava::getStrelec2() 
{
    return m_strelec2;
}

void Postava::pohyb_na_mape()
{
        
}

std::pair<int,int> Postava::getPozicia()  
{
    return pozicia;
}

void Postava::setPozicia(int x,int y) 
{
    pozicia.first = x;
    pozicia.second = y;
    sprite.setPosition(x,y);
}

void Postava::setSprite() 
{

    sprite.setTexture(m_strelec2.getView().getTexture());
    sf::FloatRect spriteSize=sprite.getGlobalBounds();
    sprite.setOrigin(spriteSize.width/2.,spriteSize.height/2.);
}

sf::Sprite Postava::getSprite() 
{
    return sprite;
}

}