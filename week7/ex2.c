#include <stdio.h>

int main() {
    int n;

    printf("n: \n");
    scanf("%d", &n);

    int* a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        a[i] = i;

    printf("Array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
	printf("\n");

    printf("Releasing memory\n");
    free(a);
    return 0;
}