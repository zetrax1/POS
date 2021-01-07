#include "hrackaPostava.hpp"
#include "strelec.hpp"
#include <memory>


namespace model
{


Postava::Postava(/* args */) :  m_strelec(std::make_shared<Strelec>())
{
}

Postava::~Postava()
{
}

std::shared_ptr<Strelec> Postava::getStrelec() 
{
    return m_strelec;
}

}