#ifndef __STRELEC_H__
#define __STRELEC_H__

#include "../view/strelec_view.hpp"
namespace model
{

class Strelec
{
private:
    view::Strelec_view view;

public:
    Strelec();
    ~Strelec();
    view::Strelec_view getView();
    
};

}
#endif // __STRELEC_H__