#include<time.h>
#include <stdio.h> 

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int num[n][m];
    int* fi = num;
    int* fq = (int*) calloc(n, sizeof (int));
    for (int i = 0; i < n * m; ++i) {
        *(fi + i) = rand() % 100 + 1;
        (*(fq + *(fi + i) - 1))++;
    }
    for (int i = 0; i < 100; i++)
        printf("Numarul %d se repeta de %d ori\n", i + 1, *(fq + i));
    return 0;
} 
