#include <stdio.h>

#define N 20
#define last (int)'~'
#define first (int)' '

int main() {
    FILE * rand = fopen("/dev/random", "r");
    if (rand == NULL){
        perror("Cannot open file\n");
        return 0;
    }

    unsigned int c;
    for (int i = 0; i < N; ++i) {
        c = fgetc(rand) % (last - first+1) + first;
        printf("%s", (char*)&c);
    }
    return 0;
}
