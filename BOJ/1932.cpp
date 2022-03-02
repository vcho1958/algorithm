#include <iostream>
#include <vector>
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> A(n);
  vector<vector<int>> B(n);
  for (int i = 0; i < n; i++)
  {
    A[i] = vector<int>(i + 1);
    for (auto &a : A[i])
      cin >> a;
  }
  B[0] = A[0];
  for (int i = 1; i < n; i++)
  {
    B[i] = vector<int>(i + 1, 0);
    B[i][0] = A[i][0] + B[i - 1][0];
    for (int j = 1; j < i; j++)
    {
      B[i][j] = A[i][j] + max(B[i - 1][j - 1], B[i - 1][j]);
    }
    B[i][i] = A[i][i] + B[i - 1][i - 1];
  }
  int maxValue = 0;
  for (auto &b : B[n - 1])
    if (maxValue < b)
      maxValue = b;
  cout << maxValue << '\n';
}