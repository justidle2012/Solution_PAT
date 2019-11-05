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
    int m, n;
    scanf("%d %d", &m, &n);

    int cnt=0;
    int i;
    bool flag = true;
    for (i=2; cnt<n; i++) {
        if (isPrime(i)) {
            cnt++;
            if (cnt>=m) {
                if (flag==true) {
                    printf("%d", i);
                    flag=false;
                } else {
                    printf(" %d", i);
                }
                if (m!=cnt && 0==(cnt-m+1)%10) {
                    flag=true;
                    printf("\n");
                }
            }
        }
    }
    //printf("\n");

    return 0;
}