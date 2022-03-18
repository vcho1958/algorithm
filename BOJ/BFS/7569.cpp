#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int bfs(vector<vector<vector<int>>>& box, queue<tuple<int,int,int>>& q, int number){
  int count = 0;
  while(q.size() && number){
    if(get<0>(q.front()) == -1)break;
    while(get<0>(q.front()) != -1){
      int y = get<1>(q.front()), x = get<2>(q.front()), z = get<0>(q.front());
      q.pop();
      if(z+1 < box.size() && box[z+1][y][x] == 0){
        box[z+1][y][x] = 1;
        q.push(make_tuple(z+1,y,x));
        number--;
      }
      if(z && box[z-1][y][x] == 0){
        box[z-1][y][x] = 1;
        q.push(make_tuple(z-1,y,x));
        number--;
      }
      if(y+1 < box[0].size() && box[z][y+1][x] == 0){
        box[z][y+1][x] = 1;
        q.push(make_tuple(z,y+1,x));
        number--;
      }
      if(y && box[z][y-1][x] == 0){
        box[z][y-1][x] = 1;
        q.push(make_tuple(z,y-1,x));
        number--;
      }
      if(x+1 < box[0][0].size() &&box[z][y][x+1] == 0){
        box[z][y][x+1] = 1;
        q.push(make_tuple(z,y,x+1));
        number--;
      }
      if(x && box[z][y][x-1] == 0){
        box[z][y][x-1] = 1;
        q.push(make_tuple(z,y,x-1));
        number--;
      }
    }
    q.pop();
    q.push(make_tuple(-1,-1,-1));
    count++;
  }
  for(auto& boxs:box)for(auto& row:boxs)for(auto& tomato:row)if(tomato == 0)return -1;
  return count;
}


int main(){
  int M,N,H, number = 0;
  cin>>M>>N>>H;
  vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
  queue<tuple<int,int,int>> q;
  for(int i = 0; i < H; i++)for(int j = 0; j < N; j++)for(int k = 0; k < M; k++){
    int input;
    cin>>input;
    if(input == 1)q.push(make_tuple(i, j, k));  
    if(input == 0)number++;
    box[i][j][k] = input;
  }
  q.push(make_tuple(-1,-1,-1));
  cout<< bfs(box, q, number);
}