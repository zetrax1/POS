#ifndef HRA_H
#define HRA_H

#include "../model/mapa.hpp"

namespace controler
{

class Hra
{

private:
    model::Mapa m_mapa;
    

public:
    Hra(/* args */);
    ~Hra();

    void setMapa(model::Mapa map);
    model::Mapa getMapa();

};

}

#endif
