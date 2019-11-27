//1063 计算谱半径
//https://pintia.cn/problem-sets/994805260223102976/problems/994805267860930560
#include <cstdio>
#include <cmath>
#include <algorithm>

struct COMPLEX {
    int real;//实部
    int imaginary;//虚部
};

const int MAXN = 1e5;
COMPLEX data[MAXN] = {};

bool mycmp(const COMPLEX &x, const COMPLEX &y) {
    return x.real*x.real+x.imaginary*x.imaginary > y.real*y.real+y.imaginary*y.imaginary;
}

int main() {
    int n;
    scanf("%d", &n);

    int i;
    for (i=0; i<n; i++) {
        scanf("%d %d", &data[i].real, &data[i].imaginary);
    }

    std::sort(data, data+n, mycmp);

    printf("%.2lf\n", sqrt(1.0*data[0].real*data[0].real+data[0].imaginary*data[0].imaginary));

    return 0;
}