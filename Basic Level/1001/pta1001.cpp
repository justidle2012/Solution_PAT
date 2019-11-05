#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	
	int ans = 0;
	while (n != 1) {
		if (n % 2 == 0) {
			//偶数
			n = n / 2; 
		} else {
			//奇数
			n = (3*n+1)/2; 
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
} 