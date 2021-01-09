#ifndef __STRELEC_VIEW_H__
#define __STRELEC_VIEW_H__

#include <SFML/Graphics.hpp>

namespace view
{


class Strelec_view
{
private:
    sf::Texture m_textura;

public:
    Strelec_view(/* args */);
    ~Strelec_view();



    sf::Texture& getTexture();

    void setTexture();

    void readTextura(sf::Texture &texture);

};

}


#endif // __STRELEC_VIEW_H__