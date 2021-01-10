#ifndef __DATA_H__
#define __DATA_H__

#include <iostream>
#include "../model/Smer_struct.hpp"

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
    Smer m_smer;
    typeMessage m_typ;

public:


    Data(int x, int y,int index, Smer, typeMessage typ = pohyb);

    Data(int index, typeMessage typ = initMessage);

    Data(int x, int y, int index, typeMessage typ = newClient);

    Data(const Data &);
    ~Data();

    int getIndex();
    typeMessage getType();

    Smer getSmer();
    std::pair<int, int> getSuradnice();


};

#endif // __DATA_H__