#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

const int sz = 1024*1024*10;

// ex2, ex3: as my laptop has 8 GB of memory and a lot of programs run in the backgroud, 
// it is hard to see the allocations of 10 MB in the memory. Next, I've run this program inside
// a docker container and I've seen that this program increases its memory consumption by 10MB each second.

int main() {
    for (int i = 0; i < 10; i++) {
        void* ptr = malloc(sz);
        memset(ptr, 0, sz);
        sleep(1);
    }
    return 0;
}
