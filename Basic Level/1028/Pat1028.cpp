//人口普查
//https://pintia.cn/problem-sets/994805260223102976/problems/994805293282607104
#include <cstdio>
#include <cstring>

struct PERSON {
    char name[8];
    char birth[12];
    int year;
    int month;
    int day;
};

bool less(const PERSON &x, const PERSON &y) {
    if (x.year!=y.year) {
        return x.year<=y.year;
    } else if (x.month!=y.month) {
        return x.month<=y.month;
    } else {
        return x.day<=y.day;
    }
}

bool more(const PERSON &x, const PERSON &y) {
    if (x.year!=y.year) {
        return x.year>=y.year;
    } else if (x.month!=y.month) {
        return x.month>=y.month;
    } else {
        return x.day>=y.day;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    //今天是 2014 年 9 月 6 日
    //所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。
    //下面的两种判断方法都正确
    int i;
    int ans = 0;
    PERSON tmp;
    PERSON old = {"", "2014/09/06", 2014, 9, 6};
    PERSON young = {"", "1814/09/06", 1814, 9, 6};
    PERSON left = young;
    PERSON right = old;    

    for (i=0; i<n; i++) {
#if 1
        scanf("%s %d/%d/%d", tmp.name, &tmp.year, &tmp.month, &tmp.day);

        //合法性判断
        if (less(tmp, right) && more(tmp, left)) {
            ans++;
            if (less(tmp, old)) {
                old = tmp;
            }
            if (more(tmp, young)) {
                young = tmp;
            }
        }
#else
        scanf("%s %s", tmp.name, tmp.birth);

        //合法性判断
        if (strcmp(tmp.birth, "2014/09/06")<=0 && strcmp(tmp.birth, "1814/09/06")>=0) {
            ans++;
            if (strcmp(tmp.birth, old.birth)<0) {
                old = tmp;
            }
            if (strcmp(tmp.birth, young.birth)>0) {
                young = tmp;
            }
        }
#endif
    }

    if (ans) {
        printf("%d %s %s\n", ans, old.name, young.name);
    } else {
        printf("0\n");
    }

    return 0;
}