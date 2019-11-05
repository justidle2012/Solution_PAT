//随机数生成
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);

    //数量 1 ~ 1000;
    unsigned int lo=1;
    unsigned int hi=1000;
    int n = 1 + rand()%1000;
    n = 1000;
    printf("%d", n);

    //最大需求量0 ~ 500
    int d = rand() % 501;
    d = 500;
    printf(" %d\n", d);

    //N个正数表示每种月饼的库存量，不超过550
    int data;
    for (int i=0; i<n; i++) {
        lo = 1;
        hi = 400;
        data = (rand()%(hi-lo+1));//万吨
        printf("%d ", data);
    }
    printf("\n");
    //N 个正数表示每种月饼的总售价
    double num;
    for (int i=0; i<n; i++) {
        lo = 1;
        hi = 55000;
        num = (rand()%(hi-lo+1)) * 10.0 / 1000.0;//亿元
        printf("%.3lf ", num);
    }
    printf("\n");

    return 0;
}