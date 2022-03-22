#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

 

void DFS(vector<string>& map, vector<vector<bool>>& check, int i, int j){
  char color = map[i][j];
  vector<pair<int,int>> s;
  s.push_back(make_pair(i,j));
  while(s.size()){
    auto I = s.back().first;
    auto J = s.back().second;
    s.pop_back();
    if(I && !check[I-1][J] && map[I-1][J] == color){
      check[I-1][J] = true;
      s.push_back(make_pair(I-1,J));
    }
    if(I < map.size()-1 && !check[I+1][J] && map[I+1][J] == color){
      check[I+1][J] = true;
      s.push_back(make_pair(I+1,J));
    }
    if(J && !check[I][J-1] && map[I][J-1] == color){
      check[I][J-1] = true;
      s.push_back(make_pair(I,J-1));
    }
    if(J < map.size()-1 && !check[I][J+1] && map[I][J+1] == color){
      check[I][J+1] = true;
      s.push_back(make_pair(I,J+1));
    }
  }
}

void DFS2(vector<string>& map, vector<vector<bool>>& check, int i, int j){
  char color = map[i][j];
  bool checked = false;
  if(color == 'R' || color == 'G')checked = true;
  vector<pair<int,int>> s;
  s.push_back(make_pair(i,j));
  while(s.size()){
    auto I = s.back().first;
    auto J = s.back().second;
    s.pop_back();
    if(I && !check[I-1][J] && (map[I-1][J] == color || (checked && (map[I-1][J] == 'R' || map[I-1][J] == 'G')))){
      check[I-1][J] = true;
      s.push_back(make_pair(I-1,J));
    }
    if(I < map.size()-1 && !check[I+1][J] && (map[I+1][J] == color || (checked && (map[I+1][J] == 'R' || map[I+1][J] == 'G')))){
      check[I+1][J] = true;
      s.push_back(make_pair(I+1,J));
    }
    if(J && !check[I][J-1] && (map[I][J-1] == color || (checked && (map[I][J-1] == 'R' || map[I][J-1] == 'G')))){
      check[I][J-1] = true;
      s.push_back(make_pair(I,J-1));
    }
    if(J < map.size()-1 && !check[I][J+1] && (map[I][J+1] == color || (checked && (map[I][J+1] == 'R' || map[I][J+1] == 'G')))){
      check[I][J+1] = true;
      s.push_back(make_pair(I,J+1));
    }
  }
}

int main(){
  int N, A = 0, B = 0;
  cin>>N;
  vector<string> map(N);
  vector<vector<bool>> check(N, vector<bool>(N,false));
  for(auto& row:map)cin>>row;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(check[i][j])continue;
      DFS(map, check, i, j);
      A++;
    }
  }
  check = vector<vector<bool>>(N, vector<bool>(N,false));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(check[i][j])continue;
      DFS2(map, check, i, j);
      B++;
    }
  }
  cout<<A<<' '<<B;
}