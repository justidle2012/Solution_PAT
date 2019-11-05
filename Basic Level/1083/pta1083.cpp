#include <cstdio>
#include <map>

const int MAXN = 1e4+2;
struct DATA {
  int index;
  int value;
};

int main() {
  int n;
  scanf("%d", &n);

  int value;
  std::map<int, int> m;
  int i;
  for (i=1; i<=n; i++) {
    scanf("%d", &value);
    if (value>=i) {
      m[value-i]++;
    } else {
      m[i-value]++;
    }
  }

  std::map<int, int>::reverse_iterator it=m.rbegin();
  bool flag=true;
  for (; it!=m.rend(); it++) {
    if (it->second>1) {
      if (flag==true) {
        printf("%d %d", it->first, it->second);
        flag=false;
      } else {
        printf("\n%d %d", it->first, it->second);
      }
    }
  }
  return 0;
}