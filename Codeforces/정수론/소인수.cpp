#include<iostream>
#include<vector>

using namespace std;



vector<int> sieve(int N) {
	vector<int> prime(N + 1, 0);
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (prime[i] != 0)continue;
		for (int j = i; j <= N; j += i) {
			prime[j] = i;
		}
	}
	return prime;
}


void print(vector<int>& arr, int N) {
	if(N > 1)print(arr, N / arr[N]);
	if(arr[N])cout<< arr[N] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int> arr = sieve(5000000);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		print(arr,n);
		cout << '\n';
	}
}