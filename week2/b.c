#include <stdio.h>

int main() {
    char s[255];
    scanf("%s", s);
    for (int i = strlen(s) - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}