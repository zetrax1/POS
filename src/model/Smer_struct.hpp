#ifndef __SMER_STRUCT_H__
#define __SMER_STRUCT_H__




struct Smer
{
    bool upFlag;
    bool downFlag;
    bool leftFlag;
    bool rightFlag;
    Smer() : upFlag(false), downFlag(false), leftFlag(false), rightFlag(false) {}
    Smer(bool up, bool down, bool left, bool right) : upFlag(up), downFlag(down), leftFlag(left), rightFlag(right) {}
};



#endif // __SMER_STRUCT_H__