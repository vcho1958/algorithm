#include<iostream>
#include<vector>


using namespace std;
vector<int> answer(2,0);
int devide(vector<vector<int>>& paper, int N, int x = 0, int y = 0){
  if(N == 1)return paper[y][x];
  int w = 0, b = 0;
  for(int i = 0; i < N; i += N/2){
    for(int j = 0; j < N; j += N/2){
      int res = devide(paper, N/2, x+i, y+j);
      if(res == 1)b++;
      else if(res == 0)w++;    
    }
  }
  if(b == 4)return 1;
  else if(w == 4)return 0;
  answer[0] += w;
  answer[1] += b;
  return -1;
}

int main(){
  int N;
  cin>>N;
  vector<vector<int>> paper(N,vector<int>(N));
  for(auto& line:paper)
    for(auto& point:line)
      cin>>point;
  int res = devide(paper, N);
  if(res != -1)answer[res] = 1;
  cout<<answer[0]<<'\n'<<answer[1]<<'\n';
}