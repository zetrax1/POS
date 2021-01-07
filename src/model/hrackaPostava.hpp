#ifndef __HRACKAPOSTAVA_H__
#define __HRACKAPOSTAVA_H__

#include <vector>
#include <memory>
#include "zbran.hpp"
#include "strelec.hpp"

namespace model
{


class Postava
{
private:
    std::shared_ptr<Strelec> m_strelec;
    std::vector<Zbran> m_zbrane;

public:
    Postava();
    ~Postava();

    std::shared_ptr<Strelec> getStrelec();
    
};


}

#endif // __HRACKAPOSTAVA_H__