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

    //生成从1到1000位的正整数
    int lo=1;
    int hi=1000;
    int len = lo + rand()%(hi-lo+1);
    int data;

    for (int i=0; i<900; i++) {
        data = rand()%10;
        printf("%d", data);
    }

    return 0;
}