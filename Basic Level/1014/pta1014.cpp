#include <cstdio>
#include <cstring>

const int MAXN = 62;

int main() {
    const char week[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    
    char a[MAXN], b[MAXN];
    scanf("%s %s", a, b);

    int i;
    int cnt = 0;
    for (i=0; a[i]!=0 && b[i]!=0; i++) {
        if (0==cnt) {
            if (a[i]>='A' && a[i]<='G' && a[i]==b[i]) {
                printf("%s ", week[a[i]-'A']);
                cnt++;
            }
        } else {
            if (((a[i]>='A' && a[i]<='N') || (a[i]>='0' && a[i]<='9')) && a[i]==b[i]) {
                if (a[i]>='0' && a[i]<='9') {
                    printf("%02d:", a[i]-'0');
                } else if (a[i]>='A' && a[i]<='N') {
                    printf("%02d:", a[i]-'A'+10);
                }
                break;
            }
        }
    }

    scanf("%s %s", a, b);
    for (i=0; a[i]!=0 && b[i]!=0; i++) {
        if (((a[i]>='A' && a[i]<='z') || (a[i]>='A' && a[i]<='Z')) && a[i]==b[i]) {
            printf("%02d", i);
            return 0;
        }
    }

    return 0;
}