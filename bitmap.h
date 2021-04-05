#include <stdlib.h>
#include <iostream>


class BitMap {
public:
    BitMap(unsigned long num_bits);
    BitMap(const BitMap& bm);
    BitMap& operator=(const BitMap& bm);
    ~BitMap();

    void insert(unsigned long n);
    unsigned int first_not_appear();

private:
    unsigned char* bytes;
    unsigned long num_bytes;
};
