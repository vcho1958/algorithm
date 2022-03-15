#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool checkNum(vector<bool>& buttons, int nowChannel){
  if(nowChannel == 0)if(!buttons[0])return false;
  while(nowChannel){
    if(!buttons[nowChannel%10])return false;
    nowChannel /= 10;
  }
  return true;
}

int countNumber(int N){
  if(N == 0)return 1;
  int c = 0;
  while(N){
    c++;
    N /= 10;
  }
  return c;
}

int main(){
  int N, M;
  cin>>N>>M;
  int  answer = N - 100 > 0 ? N -100 : 100 -N;
  int _default = answer;
  bool checked = false;
  vector<bool> buttons(10, true);
  while(M--){
    int button;
    cin>>button;
    buttons[button] = false;
  }

  for(int i = 0; !checked; i++){
    int interval = N-i > 0 ? N-i : i-N;
    if(i >= N && _default < interval)checked = true;
    if(!checkNum(buttons, i))continue;
    answer = min(answer, countNumber(i) + interval);
    if(i >= N)checked = true;
  }
  cout<<  answer<<'\n';
}