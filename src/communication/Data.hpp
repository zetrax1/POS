#ifndef __DATA_H__
#define __DATA_H__

#include <iostream>
#include "../model/Smer_struct.hpp"
#include <tuple>


enum typeMessage
{
    pohyb = 0,
    newClient = 1,
    initMessage = 2,
};

class Data
{

private:

    std::pair<int, int> suradnice;
    int m_indexClient ;
    std::tuple<bool ,bool,bool,bool> m_smer;

    typeMessage m_typ;

public:


    Data(int x, int y,int index, std::tuple<bool ,bool,bool,bool> smer, typeMessage typ = pohyb);

    Data(int index, typeMessage typ = initMessage);

    Data(int x, int y, int index, typeMessage typ = newClient);

    Data(const Data &);
    ~Data();

    int getIndex();
    typeMessage getType();

    std::tuple<bool ,bool,bool,bool> getSmer();
    std::pair<int, int> getSuradnice();


};

#endif // __DATA_H__