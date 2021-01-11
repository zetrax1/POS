#include "Data.hpp"

Data::Data(int x, int y, int index, std::tuple<bool ,bool,bool,bool> smer, typeMessage typ) : suradnice(x, y),
                                                             m_indexClient(index),
                                                             m_smer(smer),
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

std::tuple<bool ,bool,bool,bool> Data::getSmer() 
{
    return m_smer;
}

std::pair<int, int> Data::getSuradnice() 
{
    return suradnice;
}

