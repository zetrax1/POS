#include "Data.hpp"
Data::Data(int x ,int y):suradnice(x ,y)
{
}

Data::Data(const Data& d) 
{
    suradnice.first = d.suradnice.first;
    suradnice.second = d.suradnice.second;
}

Data::~Data()
{
}