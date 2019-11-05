#include <cstdio>

long long gcd(long long x, long long y) {
  long long r;
  while ((r=x%y)!=0) {
    x=y;
    y=r;
  }
  return y;
}

int main() {
  //freopen("4.in", "r", stdin);
  //freopen("4.out", "w", stdout);
  long long n1,m1,n2,m2,k;
  scanf("%lld/%lld %lld/%lld %lld", &n1, &m1, &n2, &m2, &k);

  long long l = m1*m2/gcd(m1,m2);
  l = l*k/gcd(l,k);//180
  n1 = l/m1*n1;//70
  n2 = l/m2*n2;//117
  long long n3 = l/k;//15

  if (n1>n2) {
      long long t = n1;
      n1 = n2;
      n2 = t;
  }
  long long i;
  bool flag=true;
  long long s;
  long long e;
  if (n1>=n3) {
    s=n1/n3+1;
  } else {
    s=1;
  }
  if (n2%n3==0) {
    e = n2/n3-1;
  } else {
    e = n2/n3;
  }

  for (i=s; i<=e; i++) {
    if (gcd(i,k)==1) {
      if (flag==true) {
        printf("%lld/%lld", i, k);
        flag=false;
      } else {
        printf(" %lld/%lld", i, k);
      }
    }
  }

  //fclose(stdin);
  //fclose(stdout);
  return 0;
}