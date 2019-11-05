#include <cstdio>
int main() {
    int coef, jie;

    bool flag = true;
    while (scanf("%d %d", &coef, &jie)!=EOF && jie!=0) {
        if (true==flag) {
            printf("%d %d", jie*coef, jie-1);
            flag=false;
        } else {
            printf(" %d %d", jie*coef, jie-1);
        }
    }

    if (true==flag) {
        printf("0 0");
    }

    printf("\n");

    return 0;
}