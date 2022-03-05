#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if(a.second > b.second) return true;
		if (a.second == b.second && a.first > b.first) return true;
		return false;
	}
};

int main() {
	int N, now = -1, answer = 0;
	cin >> N;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> conferences;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		conferences.push(make_pair(start, end));
	}
	while (conferences.size()) {
		while (conferences.size() && (conferences.top().first < now ))conferences.pop();
		if (conferences.empty())break;
		now = conferences.top().second;
		answer++;
		conferences.pop();
	}
	cout << answer << '\n';
}