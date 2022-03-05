#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
	int N, answer = 0, sum = 0;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> times;
	for (int i = 0; i < N; i++) {
		int time;
		cin >> time;
		times.push(time);
	}
	while (times.size()) {
		sum += times.top();
		answer += sum;
		times.pop();
	}
	cout << answer << '\n';
}