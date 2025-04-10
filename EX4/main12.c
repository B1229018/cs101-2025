#include <stdio.h>

void multi(int i, int j) {
    if (i > 9) return;
    if (j > 9) {
        printf("\n");
        multi(i + 1, 1);
        return;
    }
    printf("%d*%d=%d ", i, j, i * j);
    multi(i, j + 1);
}

int main() {
    multi(1, 1);
    return 0;
}
