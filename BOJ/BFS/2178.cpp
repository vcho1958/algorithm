#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;
int N,M;

int BFS(vector<string>& map,  vector<vector<bool>>& check, queue<pair<int,int>>& q){
  int res = 1;
  check[0][0] = true;
  while(q.size()){
    while(q.front().first != -1){
      int x = q.front().first;
      int y = q.front().second;
      
      if(x == M-1 && y == N-1)return res;
      q.pop();
      if(x && map[y][x-1]== '1' && !check[y][x-1]){
        q.push(make_pair(x-1,y));
        check[y][x-1] = true;
      }
      if(y && map[y-1][x]=='1' && !check[y-1][x]){
        q.push(make_pair(x,y-1));
        check[y-1][x] = true;
      }
      if(x < M-1 && map[y][x+1]=='1' && !check[y][x+1]){
        q.push(make_pair(x+1,y));
        check[y][x+1] = true;
      }
      if(y < N-1 && map[y+1][x]=='1' &&  !check[y+1][x]){
        q.push(make_pair(x,y+1));
        check[y+1][x] = true;
      }
    }
    res++;
    q.pop();
    q.push(make_pair(-1,-1));
  }
}


int main(){
  
  cin>>N>>M;
  vector<string> map(N);
  vector<vector<bool>>check(N,vector<bool>(M, false));
  queue<pair<int,int>> q;
  q.push(make_pair(0,0));
  q.push(make_pair(-1,-1));
  for(auto& m:map)cin>>m;
  cout<<BFS(map, check, q);
}