#include <stdio.h>
#include <string.h>

#include <sys/mman.h>
#include <unistd.h>

int main() {
    char sz[] = "This is a nice day";

    FILE* f = fopen("ex1.txt", "w+");
    if (f == NULL) {
        perror("failed to open");
        return 1;
    }

    ftruncate(fileno(f), sizeof(sz) - 1);

    size_t pagesize = sysconf(_SC_PAGE_SIZE);

    void* maddr = mmap(NULL, pagesize, PROT_WRITE | PROT_READ, MAP_SHARED, fileno(f), 0);
    if (!maddr) {
        perror("failed to mmap");
        return 1;
    }

    memcpy(maddr, sz, sizeof(sz) - 1);

    munmap(maddr, pagesize);
    fclose(f);

    return 0;
}
