#include "hra.hpp"
namespace controler
{


Hra::Hra(/* args */)
{
}

Hra::~Hra()
{
}

void Hra::setMapa(model::Mapa map) 
{
  m_mapa = map;  
}

model::Mapa Hra::getMapa() 
{
    return m_mapa;
}


}