#include <stdio.h>

void printTriangle(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printPyramid(int height) {
    if (height % 2 == 0) {
        printf("choose the odd height\n");
        return;
    }
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = height / 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printRectangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int figure, height;
    printf("right triangle - 1\nhorizontal pyramid - 2\nrectangle - 3\n");
    scanf("%d", &figure);
    printf("height of the figure\n");
    scanf("%d", &height);
    switch (figure) {
    case 1:
        printTriangle(height);
        break;
    case 2:
        printPyramid(height);
        break;
    case 3:
        printRectangle(height);
        break;
    default:
        printf("invalid choose, select figure from the list\n");
        break;
    }
    return 0;
}