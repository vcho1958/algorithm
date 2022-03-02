#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n, num1 = -1, num2 = -1, res = -1;
	bool toggle = false;
	cin >> t;
	for (int i = 0; i < t; i++, res = -1, num1 = -1, num2 = -1, toggle = false) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num1;
			if (num2 == -1) {
			}
			else if (num2 != num1 && toggle == false) {
				toggle = true;
			}
			else if (num2 != num1 && toggle == true && res == -1) {
				res = j;
			}
			else if (num2 == num1 && toggle == true && res == -1) {
				res = j - 1;
			}
			num2 = num1;
		}
		if (res == -1)res = n;
		cout << res << '\n';
	}

}
