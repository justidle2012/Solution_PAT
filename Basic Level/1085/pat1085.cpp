//1085 PAT单位排行
//https://pintia.cn/problem-sets/994805260223102976/problems/994805260353126400
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

struct PTASCORE {
    int  cnts;//人数
    double score;//加权分数

    PTASCORE() : cnts(0), score(0) {}
    PTASCORE(int a, double b) : cnts(a), score(b) {}
};

bool mycmp(const std::pair<std::string, PTASCORE> &x, const std::pair<std::string, PTASCORE> &y) {
    if (x.second.score != y.second.score) {
        //加权总分
        return x.second.score > y.second.score;
    } else {
        if (x.second.cnts != y.second.cnts) {
            //考生人数升序
            return x.second.cnts < y.second.cnts;
        } else {
            //单位码的字典序
            return x.first < y.first;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int i, j;
    std::map<std::string, PTASCORE> data;
    int idx = 0;
    char lv[8];
    double num;
    char arr[8];
    for (i=0; i<n; i++) {
        scanf(" %s %lf %s", lv, &num, arr);
        if ('B'==lv[0]) {
            num /= 1.5;
        } else if ('T'==lv[0]) {
            num *= 1.5;
        }

        for (j=0; arr[j]!=0; j++) {
            if (arr[j]>='A'&&arr[j]<='Z') {
                arr[j]+=32;
            }
        }

        data[arr].score += num;
        data[arr].cnts++;
    }

    //STL Map自定义排序
    std::vector<std::pair<std::string, PTASCORE> > myvec(data.begin(), data.end());
    std::sort(myvec.begin(), myvec.end(), mycmp);

    //输出
    int rank = 1;
    int old_score = 0;
    int size = myvec.size();
    int value;
    printf("%d\n", size);
    for (i=0; i<size; i++) {
        value = (int)myvec[i].second.score;
        if (old_score != value) {
            rank = i+1;
            old_score = value;
        }
        printf("%d %s %d %d\n", rank, myvec[i].first.c_str(), value, myvec[i].second.cnts);
    }

    return 0;
}