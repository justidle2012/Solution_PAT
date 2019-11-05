//生成数据
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {
    int seed = time(NULL);
    if (argc>1) {
        //有参数
#if 1
        std::stringstream ss;
        ss.clear();
        ss<<argv[1];
        ss>>seed;
#else    
        seed = atoi(argv[1]);
#endif        
    }
    srand(seed);

    int lo = 0;
    int hi = 9999;
    int data = lo + rand()%(hi-lo+1);
    printf("%d\n", data);

    return 0;
}