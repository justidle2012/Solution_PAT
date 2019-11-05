#include <cstdio>
#include <stack>
#include <string>
#include <cstring>

int main() {
    std::stack<char *> s;
    char *p;
    char tmp[82];
    while (scanf("%s", tmp)!=EOF) {
        p = new char[sizeof(char) * strlen(tmp) + 1];
        strcpy(p, tmp);
        s.push(p);
    }

    p = s.top();
    printf("%s", p);
    s.pop();
    delete[] p;
    while (s.empty()==false) {
        p = s.top();
        printf(" %s", p);
        s.pop();
        delete[] p;
    }

    return 0;
}