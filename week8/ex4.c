#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

const int sz = 1024*1024*10;

void print_rusage(const struct rusage *ru) {
    printf("CPU time (secs):         user=%.3f; system=%.3f\n",
            ru->ru_utime.tv_sec + ru->ru_utime.tv_usec / 1000000.0,
            ru->ru_stime.tv_sec + ru->ru_stime.tv_usec / 1000000.0);
    printf("Max resident set size:   %ld\n", ru->ru_maxrss);
    printf("Integral shared memory:  %ld\n", ru->ru_ixrss);
    printf("Integral unshared data:  %ld\n", ru->ru_idrss);
    printf("Integral unshared stack: %ld\n", ru->ru_isrss);
    printf("Page reclaims:           %ld\n", ru->ru_minflt);
    printf("Page faults:             %ld\n", ru->ru_majflt);
    printf("Swaps:                   %ld\n", ru->ru_nswap);
    printf("Block I/Os:              input=%ld; output=%ld\n",
             ru->ru_inblock, ru->ru_oublock);
    printf("Signals received:        %ld\n", ru->ru_nsignals);
    printf("IPC messages:            sent=%ld; received=%ld\n",
            ru->ru_msgsnd, ru->ru_msgrcv);
    printf("Context switches:        voluntary=%ld; "
            "involuntary=%ld\n", ru->ru_nvcsw, ru->ru_nivcsw);
}

int main() {
	struct rusage usage;
	
    for (int i = 0; i < 10; i++) {
        void* ptr = malloc(sz);
        memset(ptr, 0, sz);
        getrusage(RUSAGE_SELF, &usage);
        print_rusage(&usage);
        sleep(1);
    }
    return 0;
}
