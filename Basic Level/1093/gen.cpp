//生成数据
#include <cstdio>
#include <cstdlib>
#include <ctime>

//最大生成1e6个字符
int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
        seed = atoi(argv[1]);
    }
    srand(seed);

    //生成数量
    int n;
    int lo;
    int hi;

    //生成字符串A
    int i, j;
    char data;

    for (i=0; i<2; i++) {
        lo = 1;
        hi = 1e6;
        n = lo + rand()%(hi-lo+1);

        lo = 32;
        hi = 126;
        for (j=0; j<n; j++) {
            data = (char)(lo + rand()%(hi-lo+1));
            printf("%c", data);
        }
        printf("\n");
    }

    return 0;
}