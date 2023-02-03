#include <iostream>
using namespace std;

class bitVector
{
    private:
        uint32_t * P;
        
    public:        
    bitVector(){}

    bitVector(uint32_t bitsCount)
    {
        uint32_t size = (bitsCount % 32 == 0) ? bitsCount/32 : bitsCount/32 + 1;
        P = new uint32_t [size] {0};
    }

    ~bitVector()
    {
        delete [] P;
        P = nullptr;
    }

    void set(uint32_t changeBit)
    {
        uint32_t tmp = 1;
        P[changeBit/32] |= tmp << (changeBit - 32);
    }

    void reset(uint32_t changeBit)
    {
        uint32_t tmp = 1;
        P[changeBit/32] &= ~(tmp << changeBit - 32);
    }

    bool check(uint32_t chackBit)
    {
        uint32_t tmp = 1 << chackBit - 32;
        if (P[chackBit/32] & tmp )
        return true;
        else
        return false;    
    }
};

int main()
{
    bitVector bit{100};
    bit.set(39);
    cout << bit.check(39) << endl;
    bit.reset(39);
    cout << bit.check(39) << endl;
}




