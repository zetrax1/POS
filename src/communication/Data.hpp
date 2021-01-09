#ifndef __DATA_H__
#define __DATA_H__

class Data
{
private:
    int a;
    char b;
public:
    Data();
    Data(const Data&);
    ~Data();
};

#endif // __DATA_H__