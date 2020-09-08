#include <stdio.h>
#include <unistd.h>

// since the several routines executes this programm simultaneously, the strings are going to be shuffled

int main() {
    int n = 10;

    if (fork() == 0) {
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }
    else {
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    }
    return 0;
}
