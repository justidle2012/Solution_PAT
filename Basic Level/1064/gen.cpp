//1064 数据产生
#include <cstdio>
#include <cstdlib>
#include <ctime>

//最大生成1e6个字符
int main(int argc, char *argv[]) {
    //freopen("1.in", "w", stdout);

    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);

    //生成数量
    int n;
    int lo = 1;
    int hi = 5000000;
    n = lo + rand()%(hi-lo+1);
    n = 10000;
    printf("%d\n", n);

    //生成数据
    int i;
    int data;
    for (i=0; i<n; i++) {
        data = lo + rand()%(hi-lo+1);
        printf("%d ", data);
    }

    //fclose(stdout);

    return 0;
}