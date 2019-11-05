#include <cstdio>

bool isPrime(int n) {
    for (int i=2; i*i<=n; i++) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int i;
    int ans = 0;
    for (i=3; i<=n-2; i=i+2) {
        if (isPrime(i) && isPrime(i+2)) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}