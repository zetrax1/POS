#ifndef __HRACKAPOSTAVA_H__
#define __HRACKAPOSTAVA_H__

#include <vector>

#include "zbran.hpp"
#include "strelec.hpp"

namespace model
{


class Postava
{
private:
    Strelec m_strelec;
    std::vector<Zbran> m_zbrane;

public:
    Postava(/* args */);
    ~Postava();
};


}

#endif // __HRACKAPOSTAVA_H__