#ifndef HRA_H
#define HRA_H

#include "../model/Mapa.hpp"
#include "../model/Postava.hpp"
#include "../view/MonitorView.hpp"
#include "../communication/Client.hpp"
#include "../model/Smer_struct.hpp"
#include <tuple>
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
        bool m_isRun = true;
        std::pair<int, int> sizeWin;
        bool initialized = false;
        bool upFlag = false;
        bool downFlag = false;
        bool leftFlag = false;
        bool rightFlag = false;
        bool change = false;


        void moveItems();
        std::tuple<bool, bool, bool,bool> readSmerFromVector(int index);
        void writeToVector(int x , int y,int index);
        void writeToVector(std::tuple<bool ,bool,bool,bool> smer,int index);
        void messagePohyb(Data &data);
        void messageInit(Data &data);
        void messageNewClient(Data &data);
        bool messageReaction();
        void ovladanie_hry(sf::RenderWindow &window);
        void addNewPostava(const model::Postava &postava);

    public:
        Hra();
        ~Hra();

        void init_hra();
        void setMapa(model::Mapa map);
        model::Postava& getPostava(int i_postava);

    };

} // namespace controler

#endif
