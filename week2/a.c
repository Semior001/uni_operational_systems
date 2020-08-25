#include <stdio.h>

int main() {
    int a = __INT_MAX__;
    float b = __FLT_MAX__;
    double c = __DBL_MAX__;
    printf("int max: %d \nfloat max: %f \ndouble max: %f\n", a, b, c);
    printf("int sz: %ld \nfloat sz: %ld \ndouble sz: %ld\n" , sizeof(a), sizeof(b), sizeof(c));
    return 0;
}