#include "Data.hpp"
Data::Data(int a, char b)
{
    this->a = a; 
    this->b = b; 
}

Data::Data(const Data& d) 
{
    this->a = d.a;
    this->b = d.b; 
}


Data::~Data()
{
}