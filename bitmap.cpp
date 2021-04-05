#include "bitmap.h"


BitMap::BitMap(unsigned long num_bits) {
    num_bytes = (num_bits >> 3) + 1;
    bytes = (unsigned char *)malloc(num_bytes);
    for (unsigned long i = 0; i < num_bytes; i++) {
        bytes[0] = 0;
    }
}

BitMap::~BitMap() {
    free(bytes);
}

BitMap::BitMap(const BitMap& bm) {
    num_bytes = bm.num_bytes;
    bytes = (unsigned char *)malloc(num_bytes);
    memcpy(bytes, bm.bytes, num_bytes);
}

BitMap& BitMap::operator=(const BitMap& bm) {
    num_bytes = bm.num_bytes;
    unsigned char *old_bytes = bytes;
    bytes = (unsigned char *)malloc(num_bytes);
    memcpy(bytes, bm.bytes, num_bytes);
    free(old_bytes);
}

void BitMap::insert(unsigned long n) {
    unsigned long index = n / 8;
    unsigned long mod = n % 8;
    unsigned char curr_byte = bytes[index];
    bytes[index] |= ((unsigned int)0x80 >> mod);
}

unsigned int BitMap::first_not_appear() {
    unsigned long i = 0, j = 0;
    unsigned int base = 0x80;
    for (i = 0; i < num_bytes; i++) {
        unsigned int curr_byte = bytes[i];
        if (curr_byte != 0xff) {
            for (j = 0; j < 8; j++)
                if ((curr_byte & (base >> j)) == 0) return i * 8 + j;
        }
    }
    return i*8 + j;
}
