#include <cstdio>
#include <algorithm>

int main() {
    int n;
    char ch;
    scanf("%d %c", &n, &ch);

    /*
    1行1个  2n-1
    3行3+3+1  2n
    5行7+7+3+3+1
    7行9+9+7+7+3+3+1
    9行11
    */
    int data[23] = {};
    data[0] = 1;

    int i=0;
    int t=3;
    do {
        i++;
        data[i] = data[i-1] + 2*t;
        t += 2;
    } while (data[i] < 1000);

    //定位n
    int pos = std::upper_bound(data, data+i, n) - data;
    int j;
    if (pos<=1) {
        printf("%c\n", ch);
        if (0==pos) {
            printf("0\n");
        } else {
            printf("%d\n", n-1);
        }
    } else {
        for (i=pos; i>=1; i--) {
            for (j=0; j<pos-i; j++) {
                printf(" ");
            }
            for (j=2*i-1; j>0; j--) {
                printf("%c", ch);
            }
            printf("\n");
        }
        for (i=2; i<=pos; i++) {
            for (j=0; j<pos-i; j++) {
                printf(" ");
            }
            for (j=2*i-1; j>0; j--) {
                printf("%c", ch);
            }
            printf("\n");
        }
        printf("%d\n", n-data[pos-1]);
    }

    return 0;
}