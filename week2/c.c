#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        for (int j = i - 1; j > 0; j--) {
            printf(" ");
        }
        for (int j = (n - i) * 2; j >= 0; j--) {
            printf("*");
        }
        for (int j = i - 1; j > 0; j--) {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
