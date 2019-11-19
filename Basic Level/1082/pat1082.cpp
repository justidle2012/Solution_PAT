//1082 射击比赛
//https://pintia.cn/problem-sets/994805260223102976/problems/994805260990660608
#include <cstdio>
#include <algorithm>

struct COORD {
    char name[6];
    int x;
    int y;
};

const int MAXN = 1e4;
COORD data[MAXN] = {};

bool mycmp(const COORD &a, const COORD &b) {
    return a.x*a.x+a.y*a.y < b.x*b.x+b.y*b.y;
}

int main() {
    int n;
    scanf("%d", &n);

    int i;
    for (i=0; i<n; i++) {
        scanf("%s %d %d", data[i].name, &data[i].x, &data[i].y);
    }

    std::sort(data, data+n, mycmp);

    printf("%s %s\n", data[0].name, data[n-1].name);

    return 0;
}