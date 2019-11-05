#include <cstdio>
#include <algorithm>

struct STUDENT {
  int id;
  int dscore;
  int cscore;
};

const int MAXN = 1e5 + 2;
STUDENT stu[MAXN];
int n, l, h;

bool mycmp(const STUDENT &a, const STUDENT &b) {
  int atype, btype;
  //先判断两者分别是什么
  if (a.dscore>=h && a.cscore>=h) {
    //第1类：才德全尽
    atype=1;
  } else if (a.cscore<h && a.dscore>=h) {
    //第2类：德胜才
    atype=2;
  } else {
    if (a.dscore>=a.cscore) {
      //第3类：“才德兼亡”但尚有“德胜才”者
      atype=3;
    } else {
      //第4类
      atype=4;
    }
  }
  if (b.dscore>=h && b.cscore>=h) {
    //第1类：才德全尽
    btype=1;
  } else if (b.cscore<h && b.dscore>=h) {
    //第2类：德胜才
    btype=2;
  } else {
    if (b.dscore>=b.cscore) {
      //第3类：“才德兼亡”但尚有“德胜才”者
      btype=3;
    } else {
      //第4类
      btype=4;
    }
  }

  //比较
  if (atype==1) {
    if (btype==1) {
      if (a.dscore+a.cscore==b.dscore+b.cscore) {
        if (a.dscore!=b.dscore) {
          return a.dscore>b.dscore;
        } else {
          return a.id<b.id;
        }
      } else {
        return a.dscore+a.cscore>b.dscore+b.cscore;  
      }
    } else {
      return true;
    }
  } else if (atype==2) {
    if (btype==1) {
      return false;
    } else if (btype==2) {
      if (a.dscore+a.cscore==b.dscore+b.cscore) {
        if (a.dscore!=b.dscore) {
          return a.dscore>b.dscore;
        } else {
          return a.id<b.id;
        }
      } else {
        return a.dscore+a.cscore>b.dscore+b.cscore;  
      }
    } else {
      return true;
    }
  } else if (atype==3) {
    if (btype==1 || btype==2) {
      return false;
    } else if (btype==3) {
      if (a.dscore+a.cscore==b.dscore+b.cscore) {
        if (a.dscore!=b.dscore) {
          return a.dscore>b.dscore;
        } else {
          return a.id<b.id;
        }
      } else {
        return a.dscore+a.cscore>b.dscore+b.cscore;  
      }
    } else {
      return true;
    }
  } else {
    if (btype==4) {
      if (a.dscore+a.cscore==b.dscore+b.cscore) {
        if (a.dscore!=b.dscore) {
          return a.dscore>b.dscore;
        } else {
          return a.id<b.id;
        }
      } else {
        return a.dscore+a.cscore>b.dscore+b.cscore;  
      }
    } else {
      return false;
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &l, &h);

  int i;
  int m = 0;
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &stu[m].id, &stu[m].dscore, &stu[m].cscore);
    if (stu[m].dscore>=l && stu[m].cscore>=l) {
      m++;
    }
  }

  std::sort(stu, stu+m, mycmp);

  printf("%d", m);
  for (i=0; i<m; i++) {
    printf("\n%d %d %d", stu[i].id, stu[i].dscore, stu[i].cscore);
  }

  return 0;
}