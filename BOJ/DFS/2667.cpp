#include <iostream>
#include<vector>
#include<stack>
#include<utility>
#include<algorithm>

using namespace std;
vector<int> answer;

void DFS(vector<string>& map, int y, int x){
  stack<pair<int,int>> s;
  s.push(make_pair(x,y));
  int res = 0;
  map[y][x] = '0';
  while(s.size()){
    x = s.top().first;
    y = s.top().second;
    s.pop();
    res++;
    if(x && map[y][x-1] == '1'){
      map[y][x-1] = '0';
      s.push(make_pair(x-1,y));
    }
    if(x < map.size()-1 && map[y][x+1] == '1'){
      map[y][x+1] = '0';
      s.push(make_pair(x+1,y));
    }
    if(y && map[y-1][x] == '1'){
      map[y-1][x] = '0';
      s.push(make_pair(x,y-1));
    }
    if(y < map.size()-1 && map[y+1][x] == '1'){
      map[y+1][x] = '0';
      s.push(make_pair(x,y+1));
    }
  }
  answer.push_back(res);
}

int main(){
  int N;
  cin>>N;
  vector<string> map(N);

  for(auto& m:map)cin>>m;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(map[i][j] == '1')DFS(map, i, j);
    }
  }
  sort(answer.begin(), answer.end());
  cout<<answer.size()<<'\n';
  for(auto& a:answer)cout<<a<<'\n';
}