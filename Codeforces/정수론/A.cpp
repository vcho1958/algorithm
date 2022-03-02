#include<iostream>
#include<vector>
#include<string>
using namespace std;


class deque {

private:
	int* A;
	int front;
	int back;
	int size;
public:
	deque(int size) :size(size), front(0), back(0), A(new int[size]) {};
	~deque() { delete[] A; }
	void push_front() {
		int X;
		cin >> X;
		A[front] = X;
		front--;
		if (front < 0)front = size - 1;
	}
	void push_back() {
		int X;
		cin >> X;
		A[back] = X;
		back++;
		if (back >= size)back = 0;
	}
	int	pop_front(){
		if (front == back)return -1;
		int index = front + 1 < size ? front + 1 : 0;
		int tmp = A[front];
		front++;
		if (front >= size)front = 0;
		return tmp;
	}
	int pop_back() {
		if (front == back)return -1;
		int index = back - 1 < 0 ? size - 1 : back - 1;
		int tmp = A[index];
		front--;
		if (front < 0)front = size-1;
		return tmp;
	}
	int getsize() {
		return back - front;
	}
	int empty() {
		if (front == back)return 1;
		else return 0;
	}
	int	getfront() { 
		if (empty())return -1;
		int index = front + 1 < size ? front + 1 : 0;
		return A[index]; }
	int	getback() { 
		if (empty())return -1;
		int index = back - 1 < 0 ? size - 1 : back - 1;
		return A[index]; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	string input;
	cin >> n;
	deque A(n);
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push_back")A.push_back();
		else if (input == "push_front")A.push_front();
		else if (input == "pop_front")cout << A.pop_front()<<'\n';
		else if (input == "pop_back")cout << A.pop_back() << '\n';
		else if (input == "size")cout << A.getsize() << '\n';
		else if (input == "empty")cout << A.empty() << '\n';
		else if (input == "back")cout << A.getback() << '\n';
		else if (input == "front")cout << A.getfront() << '\n';
	}
	

}
