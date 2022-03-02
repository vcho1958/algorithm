/*

There is a square field of size n×n in which two cells are marked. These cells can be in the same row or column.

You are to mark two more cells so that they are the corners of a rectangle with sides parallel to the coordinate axes.

For example, if n=4 and a rectangular field looks like this (there are asterisks in the marked cells):

..∗.
....
∗...
....
Then you can mark two more cells as follows

∗.∗.....∗.∗.....

*/

#include<iostream>
#include<queue>
using namespace std;

typedef struct POS {
	int x;
	int y;
}pos;

struct cmp {
	bool operator()(pos p1, pos p2) {
		if (p1.y > p2.y) {
			return true;
		}
		else if (p1.y == p2.y) {
			if (p1.x > p2.x) return true;
			else return false;
		}
		return false;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n, ch;
	priority_queue<pos, vector<pos>, cmp> pos_queue;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ch = cin.get();
				if (ch == '\n')ch = cin.get();
				if (ch == '*') {
					pos dot = { k,j };
					if (pos_queue.size()) {
						pos tmp = pos_queue.top();
						if (dot.x == tmp.x) {
							if (dot.x) {
								pos_queue.push(pos{ dot.x - 1, dot.y });
								pos_queue.push(pos{ tmp.x - 1, tmp.y });
							}
							else {
								pos_queue.push(pos{ dot.x + 1, dot.y });
								pos_queue.push(pos{ tmp.x + 1, tmp.y });
							}
						}
						else if (dot.y == tmp.y) {
							if (dot.y) {
								pos_queue.push(pos{ dot.x, dot.y - 1 });
								pos_queue.push(pos{ tmp.x, tmp.y - 1 });
							}
							else {
								pos_queue.push(pos{ dot.x, dot.y + 1 });
								pos_queue.push(pos{ tmp.x, tmp.y + 1 });
							}
						}
						else {
							pos_queue.push(pos{ dot.x, tmp.y });
							pos_queue.push(pos{ tmp.x, dot.y });
						}
					}
					pos_queue.push(dot);
				}
			}
		}
		pos top = pos_queue.top();
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (top.x == k && top.y == j) {
					cout << '*';
					pos_queue.pop();
					if(pos_queue.size())top = pos_queue.top();
				}
				else cout << '.';
			}
			cout << '\n';
		}
	}


}