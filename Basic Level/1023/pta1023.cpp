#include <cstdio>

int main() {
    int data[10] = {};
    int i;
    for (i=0; i<10; i++) {
        scanf("%d", &data[i]);
    }

    //找到第一个不为零的
    for (i=1; i<10; i++) {
        if (data[i]!=0) {
            printf("%d", i);
            data[i]--;
            break;
        }
    }
    for (int i=0; i<10; i++) {
        while (data[i]>0) {
            printf("%d", i);
            data[i]--;
        }
    }
    printf("\n");

    return 0;
}