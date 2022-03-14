#include <vector>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int bfs(vector<vector<int>>& box, queue<pair<int,int>>& q, int number){
  int count = 0;
  while(q.size() && number){
    if(q.front().first == -1)break;
    while(q.front().first != -1){
      int y = q.front().first, x = q.front().second;
      q.pop();
      if(y+1 < box.size() && box[y+1][x] == 0){
        box[y+1][x] = 1;
        q.push(make_pair(y+1,x));
        number--;
      }
      if(y> 0 && box[y-1][x] == 0){
        box[y-1][x] = 1;
        q.push(make_pair(y-1,x));
        number--;
      }
      if(x+1 < box[0].size() &&box[y][x+1] == 0){
        box[y][x+1] = 1;
        q.push(make_pair(y,x+1));
        number--;
      }
      if(x > 0  && box[y][x-1] == 0){
        box[y][x-1] = 1;
        q.push(make_pair(y,x-1));
        number--;
      }
    }
    q.pop();
    q.push(make_pair(-1,-1));
    count++;
  }
  for(auto& row:box)for(auto& tomato:row)if(tomato == 0)return -1;
  return count;
}


int main(){
  int M,N, number = 0;
  cin>>M>>N;
  vector<vector<int>> box(N, vector<int>(M));
  queue<pair<int,int>> q;
  for(int i = 0; i < N; i++)for(int j = 0; j < M; j++){
    int input;
    cin>>input;
    if(input == 1)q.push(make_pair(i, j));  
    if(input == 0)number++;
    box[i][j] = input;
  }
  q.push(make_pair(-1,-1));
  cout<< bfs(box, q, number);
}