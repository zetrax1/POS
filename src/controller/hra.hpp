#ifndef HRA_H
#define HRA_H

#include "../model/mapa.hpp"
#include "../model/hrackaPostava.hpp"

#include <vector>

namespace controler
{

    class Hra
    {

    private:
        model::Mapa m_mapa;
        std::vector<model::Postava> m_postava;
        std::vector<model::Postava>::iterator i_postava;

    public:
        Hra(/* args */);
        ~Hra();

        void setMapa(model::Mapa map);
        model::Mapa getMapa();

        void addNewPostava(model::Postava postava);

        model::Postava getPostava(int i_postava);
    };

} // namespace controler

#endif
