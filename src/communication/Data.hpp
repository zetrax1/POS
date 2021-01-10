#ifndef __DATA_H__
#define __DATA_H__

#include <iostream>

enum typeMessage
{
    pohyb = 0,
    newClient = 1,
    initMessage = 2,
};

struct Smer
{
    bool upFlag;
    bool downFlag;
    bool leftFlag;
    bool rightFlag;
    Smer() : upFlag(false), downFlag(false), leftFlag(false), rightFlag(false) {}
    Smer(bool up, bool down, bool left, bool right) : upFlag(up), downFlag(down), leftFlag(left), rightFlag(right) {}
};
class Data
{

private:

    std::pair<int, int> suradnice;
    int m_indexClient ;
    Smer m_smer;
    typeMessage m_typ;

public:


    Data(int index, Smer, typeMessage typ = pohyb);

    Data(int index, typeMessage typ = initMessage);

    Data(int x, int y, int index, typeMessage typ = newClient);

    Data(const Data &);
    ~Data();

    int getIndex();
    typeMessage getType();

};

#endif // __DATA_H__