#ifndef __STRELEC_VIEW_H__
#define __STRELEC_VIEW_H__

#include <SFML/Graphics.hpp>

namespace view
{


class Strelec_view
{
private:
    sf::Texture textura;

public:
    Strelec_view(/* args */);
    ~Strelec_view();


    void setTexture();

    sf::Texture& getTexture();

};

}


#endif // __STRELEC_VIEW_H__