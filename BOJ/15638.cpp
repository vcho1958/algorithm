#include <iostream>
#include <vector>
using namespace std;

enum direction
{
  UP,
  RIGHT,
  DOWN,
  LEFT
};

int map[8][8] = {0};
vector<vector<int>> CCTV;
int min = 64;

int get_min()
{
}

int get_sqr()
{
  int tmp[8][8];
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
    }
  }
  int size = 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> map[i][j];
      if (map[i][j] && map[i][j] != 6)
      {
        vector<int> cctv(4);
        cctv[0] = i;
        cctv[1] = j;
        cctv[2] = map[i][j];
        cctv[3] = UP;
        CCTV.push_back(cctv);
      }
    }
  }
}