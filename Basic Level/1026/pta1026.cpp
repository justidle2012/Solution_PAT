#include <cstdio>
int main() {
    int c1, c2;
    scanf("%d %d", &c1, &c2);

    c2 = ((c2 - c1)/100.0+0.5)*10/10;//4577850->45779
    int hour = c2/3600;
    int minute = c2/60%60;
    int second = c2%60;
    printf("%02d:%02d:%02d\n", hour, minute, second);

    return 0;
}