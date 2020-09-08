#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000];

int main(){
    while (1) {
        scanf("%s", str);
        if (strcmp(str, "exit")) {
        	printf("bye\n");
        	return 0;
        }
        system(str);
    }
}