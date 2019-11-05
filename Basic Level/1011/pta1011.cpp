#include <cstdio>
int main() {
    long long a, b, c;
    int t;
    scanf("%d", &t);

    int i;
    for (i=1; i<=t; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a+b>c) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
    }
    return 0;
}