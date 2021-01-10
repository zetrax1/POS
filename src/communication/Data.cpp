#include "Data.hpp"

Data::Data(int index, Smer, typeMessage typ) : m_indexClient(index),
                                               m_typ(typ)
{
}

Data::Data(int index, typeMessage typ) : m_indexClient(index),
                                         m_typ(typ)
{
}

Data::Data(int x, int y, int index, typeMessage typ) : suradnice(x, y),
                                                       m_indexClient(index),
                                                       m_typ(typ)
{
}

Data::Data(const Data &d)
{
    suradnice.first = d.suradnice.first;
    suradnice.second = d.suradnice.second;
    m_typ = d.m_typ;
    m_indexClient =d.m_indexClient;
    m_typ = d.m_typ;
    m_smer = d.m_smer;
}

Data::~Data()
{
}

int Data::getIndex()
{
    return m_indexClient;
}

typeMessage Data::getType()
{
    return m_typ;
}

Smer Data::getSmer() 
{
    return m_smer;
}
