#include <cstdio>

struct STUDENT {
    char name[12];
    char id[12];
    int score;
};

const int MAXN = 1e6;
STUDENT arr[MAXN] = {};

int main() {
    unsigned long long n;
    scanf("%lld", &n);

    unsigned long long i;
    for (i=0; i<n; i++) {
        scanf("%s %s %d", &arr[i].name, &arr[i].id, &arr[i].score);
    }

    int min = 100;
    int max = 0;
    unsigned long long maxid;
    unsigned long long minid;
    for (i=0; i<n; i++) {
        if (arr[i].score > max) {
            max = arr[i].score;
            maxid = i;
        }
        if (arr[i].score < min) {
            min = arr[i].score;
            minid = i;
        }
    }

    printf("%s %s\n", arr[maxid].name, arr[maxid].id);
    printf("%s %s\n", arr[minid].name, arr[minid].id);

    return 0;
}