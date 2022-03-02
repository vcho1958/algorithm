#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, a_t = 0, b_t = 0;
		bool res = false;
		string input;
		cin >> a;
		cin >> b;
		cin >> input;
		if (((a+b)%2 && (a%2 != b%2))||((a + b) % 2 == 0 && (a % 2 == 0 && b % 2 == 0))) {
			for (int i = 0; i < input.length(); i++) {
				int opposite = input.length() - 1 - i;
				if (input[i] == '0')a_t++;
				else if (input[i] == '1')b_t++;
				if (a_t > a || b_t > b) {
					res = true;
					break;
				}
				if (input[i] == '?') {
					if (input[opposite] == '0' && a_t < a) {
						input[i] = '0';
						a_t++;
					}
					else if (input[opposite] == '1' && b_t < b) {
						input[i] = '1';
						b_t++;
					}
					else if (input[opposite] == '?' && (b_t < b || a_t  < a)) {
						char tmp = b-b_t >= a-a_t ? '1' : '0';
						input[i] = tmp;
						if (tmp == '0')a_t++;
						else b_t++;
					}
					else {
						res = true;
						break;
					}
				}
			}
			if(res)cout << -1 << '\n';
			else cout << input << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}

}