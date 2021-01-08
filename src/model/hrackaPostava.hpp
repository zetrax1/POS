#ifndef __HRACKAPOSTAVA_H__
#define __HRACKAPOSTAVA_H__

#include <vector>
#include <memory>
#include "zbran.hpp"
#include "strelec.hpp"

namespace model
{


class Postava
{
private:
    std::shared_ptr<Strelec> m_strelec;
    Strelec m_strelec2;
    std::vector<Zbran> m_zbrane;
    std::pair<int,int> pozicia;
    sf::Sprite sprite;

public:
    Postava();
    ~Postava();

    std::shared_ptr<Strelec> getStrelec();
    Strelec getStrelec2();


    void pohyb_na_mape();
    std::pair<int,int> getPozicia();
    void setPozicia(int x ,int y);

    void setSprite();
    sf::Sprite getSprite();
    
    
};


}

#endif // __HRACKAPOSTAVA_H__