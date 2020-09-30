#include <stdlib.h>
#include <stdio.h>


int main(){
	// seeding random
	srand(time(NULL));

	printf("n1:");
	int n1;
	scanf("%d", &n1);

	int* a = malloc(n1*sizeof(int));
	for(int i = 0; i < n1; i++){
		a[i]=100;
		printf("%d ", a[i]);
	}

	printf("\nn2: ");
	int n2=0;
	scanf("%d",&n2);

	a = realloc(a, n2 * sizeof(int));
	
	if (n2 > n1) {
        for (int i = n1; i < n2; i++)
            a[i] = 0;
	}

	for(int i = 0; i < n2; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}