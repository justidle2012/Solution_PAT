#include <cstdio>

int main() {
    int num[127] = {};//统计次数
    char ch;

    while ((ch=getchar())!=EOF) {
        if (ch<32 || ch>126) {
            continue;
        }
        if (num[ch]==0) {
            printf("%c", ch);
        }
        num[ch]++;
    }

    return 0;
}