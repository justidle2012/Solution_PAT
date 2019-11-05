#include <cstdio>

const int MAXN = 1e5;
char num[MAXN];
int  cnt_num = 0;

int main() {
    //由于不知道字符有多长，一个个读入
    char ch;
    bool flag_coef = false;//系数正负，false表示正数，true表示负数
    bool flag_e = false;
    int  coef = 0;

    //读入符号位
    ch = getchar();
    if ('-'==ch) {
        printf("-");
    }

    //以E为
    while ((ch=getchar())!=EOF && (ch!='\n')) {
        if (flag_e==false) {
            if ('E'==ch) {
                flag_e = true;
            } else {
                if ('.'!=ch) {
                    num[cnt_num++] = ch;
                }
            }
        } else {
            if ('-'==ch) {
                flag_coef = true;
            } else if ('+'==ch) {
                flag_coef = false;
            } else {
                coef = coef*10 + (ch-'0');
            }
        }
    }

    int i;
    if (false==flag_coef) {
        //先打num，再向后加零
        if (coef <= cnt_num-1) {
            for (i=0; i<coef+1; i++) {
                printf("%c", num[i]);
            }
            if (coef < cnt_num-1) {
                printf(".");
            }
            for (i=coef+1; i<cnt_num; i++) {
                printf("%c", num[i]);
            }
        } else {
            for (i=0; i<cnt_num; i++) {
                printf("%c", num[i]);
            }
            for (i=0; i<coef-cnt_num+1; i++) {
                printf("0");
            }
        }
    } else {
        printf("0.");
        for (i=0; i<coef-1; i++) {
            printf("0");
        }
        for (i=0; i<cnt_num; i++) {
            printf("%c", num[i]);
        }
    }
    printf("\n");

    return 0;
}