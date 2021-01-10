#ifndef __MAPA_VIEW_H__
#define __MAPA_VIEW_H__

#include <SFML/Graphics.hpp>


namespace view
{

    class Mapa_view
    {
    private:
        /* data */
    public:
        Mapa_view(/* args */);
        ~Mapa_view();

        void readTextura(sf::Texture &texture);
    };

} // namespace view

#endif // __MAPA_VIEW_H__