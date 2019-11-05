#include <cstdio>

bool judge(const char str[]) {
  int i;
  /*
  1、找出P和T位置。
  2、统计P前的A个数，P和T之间的A个数，T后的A个数
  3、如果 P前 * P和T间 = T后 ，则是合法
  */
  int cnt_p = 0;//P的个数
  int cnt_t = 0;//T的个数
  int cnt0 = 0;//P前A个数
  int cnt1 = 0;//P和T之间A个数
  int cnt2 = 0;//T后A个数
  for (i=0; str[i]!=0; i++) {
    //字符串中必须仅有 P、 A、 T这三种字符
    if ('P'!=str[i] && 'A'!=str[i] && 'T'!=str[i]) {
      return false;
    }

    if ('P'==str[i]) {
      cnt_p++;
      //判断P的合法性
      if (cnt_t!=0 || cnt_p>1) {
        return false;
      }
    } else if ('T'==str[i]) {
      cnt_t++;
      //判断T的合法性
      if (cnt_p==0 || cnt_t>1) {
        return false;
      }
    } else {
      //A统计
      if (0==cnt_p && 0==cnt_t) {
        cnt0++;
      } else if (0!=cnt_p && 0==cnt_t) {
        cnt1++;
      } else {
        cnt2++;
      }
    }
  }

  //合法性判断
  if (0==cnt_p || 0==cnt_t || 0==cnt1) {
    //中间没有A。比如PT这个
    return false;
  } else if (cnt0*cnt1!=cnt2) {
    return false;
  } else {
    return true;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  char str[102];
  int i, j;
  bool flag = true;
  for (i=0; i<n; i++) {
    scanf("%s", str);

    //分析
    if (judge(str)) {
      if (true==flag) {
        printf("YES");
        flag=false;
      } else {
        printf("\nYES");
      }
    } else {
      if (true==flag) {
        printf("NO");
        flag=false;
      } else {
        printf("\nNO");
      }
    }
  }

  return 0;
}