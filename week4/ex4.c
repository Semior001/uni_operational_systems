#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char str[1000];

int main(){
    while (1) {
        scanf("%s", str);
        if (strcmp(str, "exit") == 0) {
        	printf("bye\n");
        	return 0;
        }
        if (fork() == 0) {
            system(str);
            exit(0);
        }
    }
}