#ifndef __DATA_H__
#define __DATA_H__

#include <iostream>

enum typeZbran
{
    pohyb = 0,
    newClient = 1,
};

class Data
{
private:
    std::pair<int,int> suradnice;
    typeZbran m_typ;

public:
    Data(int x ,int y);
    Data(const Data&);
    ~Data();
};

#endif // __DATA_H__