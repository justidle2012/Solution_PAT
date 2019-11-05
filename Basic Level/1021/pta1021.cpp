#include <cstdio>

int main() {
    unsigned long long num[10] = {};
    char ch;
    while (((ch=getchar())!=EOF) && (ch!='\n')) {
        num[ch-'0']++;
    }

    for (int i=0; i<10; i++) {
        if (num[i]>0) {
            printf("%d:%llu\n", i, num[i]);
        }
    }

    return 0;
}