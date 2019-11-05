#include <cstdio>
#include <algorithm>

int main() {
  int data[4];
  int ans;
  scanf("%d", &ans);

  int num1, num2;
  bool flag=true;
  do {
    data[0] = ans%10;
    data[1] = ans/10%10;
    data[2] = ans/100%10;
    data[3] = ans/1000%10;
    std::sort(data, data+4);
    num1 = data[3]*1000+data[2]*100+data[1]*10+data[0];
    num2 = data[0]*1000+data[1]*100+data[2]*10+data[3];
    ans  = num1 - num2;
    if (flag==true) {
      flag=false;
      printf("%04d - %04d = %04d", num1, num2, ans);
    } else {
      printf("\n%04d - %04d = %04d", num1, num2, ans);
    }
  } while (!(ans==0 || ans==6174));
  
  return 0;
}