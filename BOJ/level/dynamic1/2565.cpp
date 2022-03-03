#include <iostream>
#include <vector>


using namespace std;
int main(){
  int N, max = 1;
  cin >> N;
  vector<int> lines(500, 0);
  vector<int> answer(500, 1);
  for(int i = 0; i < N; i++){
    int index, value;
    cin >> index >> value;
    lines[index-1] = value;
  } 
  for(int i = 0; i < 500; i++){
    if(lines[i] == 0)continue;
    for(int j = 0; j < i; j++){
      if(lines[j] == 0)continue;
      if(lines[j] < lines[i] && answer[j] + 1 > answer[i])answer[i] = answer[j] + 1;
    }
    if(answer[i] > max) max = answer[i];
  }
  cout<<N-max<<'\n';
  return 0; 
}