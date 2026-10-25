#include <stdio.h>
#include <stdlib.h>


#define dathuctoigian 0x1B //m(x) = x^8 + x^4 + x^3 + x + 1

unsigned char gf28_mul(unsigned char a, unsigned char b) {
    unsigned char p = 0; 

    while (b > 0) {
        if (b & 1) {
            p ^= a; 
        }

        unsigned char hi_bit_set = a & 0x80;
        a <<= 1;

        if (hi_bit_set) {
            a ^= dathuctoigian;
        }

        a &= 0xFF; 
        b >>= 1;
    }
    return p;
}

void inDaThuc(unsigned char val) {
    if (val == 0) {
        printf("0");
        return;
    }

    int first = 1;

    for (int i = 7; i >= 0; i--) {
        if ((val >> i) & 1) {
            if (!first) printf(" + ");
            if (i == 0) printf("1");
            else if (i == 1) printf("x");
            else printf("x^%d", i);
            first = 0;
        }
    }
}

int main() {

    unsigned char A = 0b01010111;
    unsigned char B = 0b10000011;
    unsigned char ketqua = gf28_mul(A, B);

    printf("A * B trong GF(2^8) = ");
    inDaThuc(ketqua);
    printf("\n");
    system("pause");
    return 0;
}