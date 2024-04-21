#include <iostream>

int main() {
    int n = 5;

    // outer loop
    for (int row = 1; row < 2 * n; row++) {

        int spaces, cols;
        if (row < n) {
            cols = n + 1 - row;
            spaces = row - 1;
        } else {
            spaces = 2 * n - 1 - row;
            cols = row + 1 - n;
        }

        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }

        for (int j = 1; j <= cols; j++) {
            if (j == 1 || j == cols || row == 2 * n - 1 || row == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}