#ifndef HRA_H
#define HRA_H

#include "../model/mapa.hpp"
#include "../model/hrackaPostava.hpp"
#include "../view/monitor_view.hpp"

#include <vector>


#define         SPRITE_SPEED        5
namespace controler
{

    class Hra
    {

    private:
        model::Mapa m_mapa;
        std::vector<model::Postava> m_postava;
        std::vector<model::Postava>::iterator i_postava;
        sf::Event event;
        view::Monitor_view *m_monitorView;

        bool upFlag = false;
        bool downFlag = false;
        bool leftFlag = false;
        bool rightFlag = false;

    public:
        Hra(/* args */);
        ~Hra();

        void init_hra();

        void setMapa(model::Mapa map);
        model::Mapa getMapa();

        void addNewPostava(const model::Postava &postava);

        model::Postava& getPostava(int i_postava);

        void ovladanie_hry();

    };

} // namespace controler

#endif
