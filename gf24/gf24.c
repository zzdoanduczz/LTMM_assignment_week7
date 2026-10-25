#include <stdio.h>
#include <stdlib.h>

#define dathuctoigian 0x03 //m(x) = x^4 + x + 1

unsigned char gf24_mul(unsigned char a, unsigned char b) {
    unsigned char p = 0;   

    while (b > 0) {
        if (b & 1) {
            p ^= a;   
        }

        unsigned char hi_bit_set = a & 0x08;
        a <<= 1;

        if (hi_bit_set) {
            a ^= dathuctoigian; 
        }

        a &= 0x0F;
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
    for (int i = 3; i >= 0; i--) {
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
    unsigned char A = 0b0101;
    unsigned char B = 0b1011;
    unsigned char ketqua = gf24_mul(A, B);

    printf("A * B trong GF(2^4) = ");
    inDaThuc(ketqua);
    printf("\n");
    system("pause");
    return 0;
}