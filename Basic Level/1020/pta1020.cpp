#include <cstdio>
#include <algorithm>

struct MOONCAKE {
    double stock;//库存
    double price;//总售价
    double single;//单价
};

bool mycmp(const MOONCAKE &x, const MOONCAKE &y) {
    return (x.single > y.single);
}

int main() {
    freopen("data.in", "r", stdin);
    int n, d;
    scanf("%d %d", &n, &d);

    MOONCAKE data[1000] = {};

    int i;
    for (i=0; i<n; i++) {
        scanf("%lf", &data[i].stock);
    }
    for (i=0; i<n; i++) {
        scanf("%lf", &data[i].price);
        data[i].single = 1.0*data[i].price/data[i].stock;
    }

    //排序
    std::sort(data, data+n, mycmp);

    double ans = 0;
    for (i=0; i<n && d>0; i++) {
        if (d>=data[i].stock) {
            ans += data[i].price;
            d -= data[i].stock;
        } else {
            ans += d*data[i].single;
            d = 0;
        }
    }
    printf("%.2lf\n", ans);

    fclose(stdin);
    return 0;
}