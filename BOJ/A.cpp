#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ull = unsigned long long;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<string> powers;
  ull a = 1;
  while (a <= 1000000000000000000)
  {
    powers.push_back(to_string(a));
    a <<= 1;
  }
  //for (auto &p : powers)
  //  cout << p << '\n';
  int t;
  cin >> t;
  while (t--)
  {
    string input;
    cin >> input;
    int max = 0, mainsub = 0;
    for (auto p : powers)
    {
      int i = 0, j = 0, count = 0, sub = 0;
      while (j < p.length() && i < input.length())
      {
        if (input[i] == p[j])
        {
          count++;
          j++;
        }
        i++;
      }
      sub = p.length() - j - 1;
      if (count - sub > max - mainsub)
      {
        max = count;
        mainsub = sub;
      }
    }
    cout << input.length() - max + mainsub + 1 << '\n';
  }
}