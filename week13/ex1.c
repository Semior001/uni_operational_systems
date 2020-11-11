#define MAX_N 100
#define MAX_M 100

#include <stdio.h>

int main() {
    FILE *in = fopen("./ex1.in", "r");
    int n = 0, m = 0, E[MAX_M], A[MAX_M], R[MAX_N][MAX_M], C[MAX_N][MAX_M], used[MAX_N];

    char c;
    do {
        fscanf(in, "%d%c", &E[m], &c);
        m++;
    } while (c != '\n');

    for (int i = 0; i < m; i++) {
        fscanf(in, "%d", &A[i]);
    }

    int x1;
    while(1) {
        for (int i = 0; i < m; i++) {
            fscanf(in, "%d", &C[n][i]);
        }
        n++;
        x1 = fscanf(in, "%c%c", &c, &c);
        if (c == '\n') {
            break;
        }
        fseek(in, -1, SEEK_CUR);
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(in, "%d", &R[i][j]);
        }
    }

    int x = n, ans[MAX_N];
    while (x) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                int f = 1;
                for (int j = 0; j < m; j++) {
                    if(R[i][j] > A[j]) {
                        f = 0;
                        break;
                    }
                }
                if (f) {
                    used[i] = 1;
                    ans[n - x] = i + 1;
                    for (int j = 0; j < m; j++) {
                        A[j] += C[i][j];
                    }
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            printf("Deadlock\nProcesses: ");
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
            return 0;
        }
        x--;
    }

    printf("No deadlock\nExecution order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}