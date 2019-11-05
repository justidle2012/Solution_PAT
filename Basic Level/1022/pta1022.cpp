#include <cstdio>

int main() {
    long long a, b, d;
    scanf("%lld %lld %lld", &a, &b, &d);

    long long t;
    t = a+b;

    //进制转换
    char ans[1000] = {};
    int idx = 0;
    while (t) {
        ans[idx++] = t%d+'0';
        t /= d;
    }

    if (idx==0) {
        printf("0\n");
    } else {
        for (int i=idx-1; i>=0; i--) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }

    return 0;
}