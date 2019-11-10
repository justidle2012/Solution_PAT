#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

struct STUDENT {
    string zkz;
    int score;

    //构造函数
    STUDENT() : zkz(""), score(0) {}
    STUDENT(string s, int n) : zkz(s), score(n) {}
};

const int MAXN = 1e4;
STUDENT arr[MAXN];

bool mycmp(const STUDENT &x, const STUDENT &y) {
    //按分数非升序输
    if (x.score == y.score) {
        //按其准考证号的字典序递增输出
        return x.zkz<y.zkz;
    } else {
        return x.score>y.score;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int i;
    for (i=0; i<n; i++) {
        arr[i].zkz.resize(14);
        scanf (" %s %d", &arr[i].zkz[0], &arr[i].score);
    }

    int type;//类型
    string cmd;//命令
    int j;
    for (j=0; j<m; j++) {
        cmd.resize(14);
        scanf(" %d %s", &type, &cmd[0]);
        printf("Case %d: %d %s\n", j+1, type, cmd.c_str());

        vector<STUDENT> ans;
        bool flag=true;
        if (1==type) {
            //按分数非升序输出某个指定级别的考生的成绩
            for (i=0; i<n; i++) {
                if (cmd[0] == arr[i].zkz[0]) {
                    ans.push_back(arr[i]);
                    flag = false;
                }
            }
        } else if (2==type) {
            //将某指定考场的考生人数和总分统计输出
            unsigned long long cnt = 0;
            unsigned long long ans = 0;
            for (i=0; i<n; i++) {
                if (cmd.substr(0,3)==arr[i].zkz.substr(1,3)){
                    cnt++;
                    ans += arr[i].score;
                    flag = false;
                }
            }

            if (false == flag) {
                printf("%llu %llu\n", cnt, ans);
            }
        } else if (3==type) {
            //将某指定日期的考生人数分考场统计输出
            std::unordered_map<std::string, int> status;
            
            for (i=0; i<n; i++) {
                if (cmd.substr(0,6)==arr[i].zkz.substr(4,6)){
                    status[arr[i].zkz.substr(1,3)]++;
                }
            }

            std::unordered_map<std::string, int>::iterator it;
            for (it=status.begin(); it!=status.end(); it++) {
                ans.push_back(STUDENT(it->first, it->second));
                flag = false;
            }
        }

        if (true == flag) {
            printf("NA\n");
        } else {
            sort(ans.begin(), ans.end(), mycmp);
            for (i=0; i<ans.size(); i++) {
                printf("%s %d\n", ans[i].zkz.c_str(), ans[i].score);
            }
        }
    }

    return 0;
}