#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
using bigg = unsigned long long;
bigg addmod(bigg a, bigg b, bigg n)
{
  bigg amod = a % n;
  bigg bmod = b % n;
  if (!amod)
    return bmod;
  if (!bmod)
    return amod;
  if (amod + bmod <= amod)
    return (amod - (n - bmod)) % n;
  return (amod + bmod) % n;
}

bigg mulmod(bigg a, bigg b, bigg n)
{
  bigg amod = a % n;
  bigg bmod = b % n;
  if (amod == 0 || bmod == 0)
    return 0;
  if (amod == 1)
    return bmod;
  if (bmod == 1)
    return amod;
  bigg asquared = mulmod(amod, bmod / 2, n);
  if (bmod & 1)
    return addmod(amod, addmod(asquared, asquared, n), n);
  return addmod(asquared, asquared, n);
}

bigg sqmod(bigg a, bigg b, bigg n)
{
  if (b == 0)
    return 1;
  bigg amod = a % n;
  if (b == 1)
    return a % n;
  bigg h = sqmod(amod, b / 2, n);
  if (b & 1)
  {
    return mulmod(amod, mulmod(h, h, n), n);
  }
  return mulmod(h, h, n);
}

main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  bigg m = 1234567891, r = 31, sum = 0;
  int L;
  string input;
  cin >> L >> input;

  for (int i = 0; i < L; i++)
  {
    bigg target = input[i] - 'a' + 1;
    bigg r2 = sqmod(r, i, m);
    bigg right = mulmod(target, r2, m);
    sum = addmod(sum, right, m);
  }
  cout << sum << '\n';
}