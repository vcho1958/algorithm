#include <iostream>
#include <vector>

using namespace std;
int main(){
  int N;
  cin>>N;
  vector<vector<int>> house(N, vector<int>(3));
  vector<vector<int>> answers(N, vector<int>(3));
  for(auto& colors: house)
    for(auto& color: colors)cin>>color;
  for(int i = 0; i < 3; i++)answers[0][i] = house[0][i];
  for(int i = 1; i < N; i++){
    for(int j = 0; j < 3; j++){
      int min = -1;
      for(int k = 0; k < 3; k++){
        if(k == j)continue;
        if(min == -1|| min > answers[i-1][k])min = answers[i-1][k];
      }
      answers[i][j] = min + house[i][j];
    }
  }
  int min = answers[N-1][0];
  for(int i = 1 ; i < 3; i++){
    if(min > answers[N-1][i])min = answers[N-1][i];
  }
  cout<< min;
}