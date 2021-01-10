#ifndef __POSTAVA_H__
#define __POSTAVA_H__

#include <vector>
#include <memory>
#include "Zbran.hpp"
#include "Strelec.hpp"
#include "../model/Smer_struct.hpp"

namespace model
{


class Postava
{
private:
    std::shared_ptr<Strelec> m_strelec;
    std::vector<Zbran> m_zbrane;
    std::pair<int,int> m_pozicia;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    Smer m_smer;

public:
    Postava();
    ~Postava();

    std::shared_ptr<Strelec> getStrelec();

    void pohyb_na_mape();
    std::pair<int,int> getPozicia();
    void setPozicia(int x ,int y);

    void setSprite();
    sf::Sprite getSprite();

    void setSmer(bool up, bool down, bool left, bool right);
    void setSmer(Smer sm);
    Smer getSmer();
    
};


}

#endif // __HRACKAPOSTAVA_H__