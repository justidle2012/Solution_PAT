#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);

    long long ans1 = 0;
    long long ans2 = 0;
    long long ans3 = 0;
    long long ans4 = 0;
    long long ans5 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int cnt4 = 0;
    int cnt5 = 0;
    int i;
    int num;
    for (i=0; i<n; i++) {
        scanf("%d", &num);
        if (0==num%5) {
            if (num%2==0) {
                ans1+=num;
                cnt1++;
            }
        } else if (1==num%5) {
            if (0==cnt2%2) {
                ans2+=num;
            } else {
                ans2-=num;
            }
            cnt2++;
        } else if (2==num%5) {
            ans3++;
            cnt3++;
        } else if (3==num%5) {
            ans4+=num;
            cnt4++;
        } else if (4==num%5) {
            if (ans5<num) {
                ans5=num;
                cnt5++;
            }
        } 
    }

    if (0==cnt1) {
        printf("N ");
    } else {
        printf("%lld ", ans1);
    }
    if (0==cnt2) {
        printf("N ");
    } else {
        printf("%lld ", ans2);
    }
    if (0==cnt3) {
        printf("N ");
    } else {
        printf("%lld ", ans3);
    }
    if (0==cnt4) {
        printf("N ");
    } else {
        printf("%.1lf ", (double)ans4/cnt4);
    }
    if (0==cnt5) {
        printf("N");
    } else {
        printf("%lld", ans5);
    }
    printf("\n");

    return 0;
}