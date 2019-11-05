#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> a;//没有计算的
    set<int> b;//已经计算过的
    set<int>::iterator it;

    int k, n, t;
    cin >> k;
    for (int i=0; i<k; i++) {
    	cin >> n;

        t = n;
        it = b.find(t);
        if (b.end() == it) {
            //没有
            while (t != 1) {
                if (t % 2 == 0) {
                    //偶数
                    t = t / 2; 
                } else {
                    //奇数
                    t = (3*t+1)/2; 
                }

                //t
                it = b.find(t);
                if (b.end() == it) {
                    b.insert(t);
                } else {
                    it = a.find(t);
                    if (a.end() != it) {
                        a.erase(t);
                    }
                    break;
                }
            }

            a.insert(n);
            b.insert(n);
        }
    }

    set<int>::reverse_iterator r_iter = a.rbegin();
    printf("%d", *r_iter);
    for (r_iter++; r_iter != a.rend(); ++r_iter) {
        printf(" %d", *r_iter);
    }
    printf("\n");

	return 0;
} 