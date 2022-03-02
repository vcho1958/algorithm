#include <iostream>
#include <vector>
using namespace std;

int canGenerate(int n, vector<bool> &A)
{
  int count = 0;
  if (n == 0)
  {
    if (A[0])
      return 0;
    return 1;
  }

  while (n)
  {
    if (A[n % 10])
      return 0;
    count++;
    n /= 10;
  }
  return count;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int target, m, interval = 0;
  cin >> target >> m;
  vector<bool> A(10, 0);
  while (m--)
  {
    int button;
    cin >> button;
    A[button] = true;
  }
  int start = 100, count = target - start > 0 ? target - start : start - target;
  if (target > start)
  {
    while (target - interval > 100)
    {
      int left = target - interval, right = target + interval, tmp;
      if (tmp = canGenerate(left, A))
      {
        count = tmp + interval;
        break;
      }
      else if (tmp = canGenerate(right, A))
      {
        count = tmp + interval;
        break;
      }
      interval++;
    }
  }
  else if (target < start)
  {
    while (target + interval < 100)
    {
      int left = target - interval, right = target + interval, tmp;
      if (tmp = canGenerate(left, A))
      {
        count = tmp + interval;
        break;
      }
      else if (tmp = canGenerate(right, A))
      {
        count = tmp + interval;
        break;
      }

      interval++;
    }
  }

  //cout << count;
}
