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
        communication::Client client;
        int m_indexClient = 0;
        std::mutex mutex_;


    public:
        Hra();
        ~Hra();

        void init_hra();

        void setMapa(model::Mapa map);

        void addNewPostava(const model::Postava &postava);

        model::Postava& getPostava(int i_postava);

        void ovladanie_hry(sf::RenderWindow &window);

        bool messageReaction();

        void messagePohyb();
        void messageInit();
        void messageNewClient();
    };

} // namespace controler

#endif
