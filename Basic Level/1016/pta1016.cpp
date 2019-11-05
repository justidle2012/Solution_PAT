#include <cstdio>

int main() {
  long long a, b;
  long long da, db;

  scanf("%lld %lld %lld %lld", &a, &da, &b, &db);

  long long va=0, vb=0;
  while (a) {
    if (a%10==da) {
      va = va*10 + da;
    }
    a /= 10;
  }
  while (b) {
    if (b%10==db) {
      vb = vb*10 + db;
    }
    b /= 10;
  }

  printf("%lld\n", va+vb);
  return 0;
}