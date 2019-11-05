#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);

    int b = n / 100;
    int s = n / 10 % 10;
    int g = n % 10;

    int i;
    for (i=0; i<b; i++) {
        printf("B");
    }
    for (i=0; i<s; i++) {
        printf("S");
    }
    for (i=1; i<=g; i++) {
        printf("%d", i);
    }
    printf("\n");

    return 0;
}