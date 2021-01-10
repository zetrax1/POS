#ifndef __DATA_H__
#define __DATA_H__

#include <utility>

class Data
{
private:

public:
    int a;
    char b;
    Data(int a, char b);
    Data(const Data&);
    ~Data();
};

#endif // __DATA_H__