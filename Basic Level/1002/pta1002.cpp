#include <cstdio>
#include <stack>

int main() {
    char ch;
    unsigned long long ans = 0;

    do {
        ch = getchar();
        if (ch=='\n' || ch==EOF) {
            break;
        }
        ans += (ch - '0');
    } while (1);

    char chn[][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    std::stack<char *> s;
    while (ans) {
        s.push(chn[ans%10]);
        ans /= 10;
    }

    printf("%s", s.top());
    s.pop();
    while (s.empty()==false) {
        printf(" %s", s.top());
        s.pop();
    }
    printf("\n");

    return 0;
}