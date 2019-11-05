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
    unsigned int lo=0;
    unsigned int hi=10000;
    unsigned int data;
    
    int i;
    for (i=0; i<10; i++) {
        data = lo + rand()%(hi-lo+1);
        printf("%d ", data);
    }
    printf("\n");

    return 0;
}