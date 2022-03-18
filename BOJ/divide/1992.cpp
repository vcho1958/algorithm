#include<iostream>
#include<vector>


using namespace std;
string devide(vector<string>& paper, int N, int x = 0, int y = 0){
  int w = 0, b = 0;
  string _return;
  if(N == 1)return _return + paper[y][x];
  for(int i = y; i < y+N; i += N/2){
    for(int j = x; j < x+N; j += N/2){
      string res = devide(paper, N/2, j , i);
      if(res == "1")b++;
      else if(res == "0")w++;
      _return += res;
    }
  }
  if(b == 4)return "1";
  else if(w == 4)return "0";
  return "("+_return+")";
}

int main(){
  int N;
  cin>>N;
  vector<string> paper(N);
  for(auto& line:paper)
      cin>>line;

  cout<<devide(paper, N)<<'\n';
}