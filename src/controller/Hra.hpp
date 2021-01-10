#ifndef HRA_H
#define HRA_H

#include "../model/Mapa.hpp"
#include "../model/Postava.hpp"
#include "../view/MonitorView.hpp"
#include "../communication/Client.hpp"

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
        communication::Client client;

        bool upFlag = false;
        bool downFlag = false;
        bool leftFlag = false;
        bool rightFlag = false;

    public:
        Hra(/* args */);
        ~Hra();

        void init_hra();

        void setMapa(model::Mapa map);

        void addNewPostava(const model::Postava &postava);

        model::Postava& getPostava(int i_postava);

        void ovladanie_hry();

    };

} // namespace controler

#endif
