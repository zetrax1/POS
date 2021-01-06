#ifndef __ZBRAN_H__
#define __ZBRAN_H__

enum typeZbran
{
    pistol = 0,
    samopal = 1,
    brokovnica = 2,
};

namespace model
{

    class Zbran
    {
    private:
        typeZbran m_type;
        
    public:
        Zbran(typeZbran type = pistol);
        ~Zbran();
    };

} // namespace model

#endif // __ZBRAN_H__
