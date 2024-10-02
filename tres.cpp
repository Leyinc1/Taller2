
#include <stdio.h>

int main() {
    int n;
    int j;
    int i;

    printf("Escribe N: \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            printf("0");
        }
        printf("1\n");
    }

    return 0;
}
