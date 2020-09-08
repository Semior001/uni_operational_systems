#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("give the n as cli argument\n");
		return 0;
	}
    int n;
    sscanf(argv[1], "%d", &n);
    // scanf("%d", &n);
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
