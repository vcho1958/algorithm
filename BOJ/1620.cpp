#include <iostream>
#include <vector>
using namespace std;
vector<int> res(3, 0);
int check(int n, int i, int j, vector<vector<int>> &a)
{
}

void count(int n, vector<vector<int>> &a, vector<int> &res)
{
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(n));

  for (auto &a : A)
    for (auto &a2 : a)
      cin >> a2;
  count(n, A, res);
  cout << res[0] << '\n'
       << res[1] << '\n'
       << res[2];
}