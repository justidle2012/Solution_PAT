#include <cstdio>

const int MAXN = 100;
int data[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int i;
    int num;
    for (i=0; i<n; i++) {
        scanf("%d", &num);
        data[(i+m)%n] = num;
    }

    printf("%d", data[0]);
    for (i=1; i<n; i++) {
        printf(" %d", data[i]);
    }
    printf("\n");

    return 0;
}