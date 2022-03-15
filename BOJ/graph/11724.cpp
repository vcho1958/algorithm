#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

bool BFS(vector<vector<int>>& edges, int u){
  bool checked = 0;
  for(int j = 0; j < edges.size(); j++){
    if(edges[u][j] == 0)continue;
    edges[u][j] = 0;
    edges[j][u] = 0;
    checked = 1;
    BFS(edges, j);
  }
  return checked;
}

int main(){
  int N, M, answer = 0;
  cin>>N>>M;
  vector<vector<int>> edges(N, vector<int>(N, 0));
  while(M--){
    int u, v;
    cin >> u >> v;
    edges[u-1][v-1] = 1;
    edges[v-1][u-1] = 1;
  }
  for(int i = 0; i < N; i++){
    edges[i][i] = 1;
  }

  for(int i = 0; i < N; i++){
    if(BFS(edges, i))answer++;
  }
  cout<<answer<<'\n';
}








