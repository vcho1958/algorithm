#include <iostream>
#include <string>


using namespace std;

int main(){
  int N,M, res = 0;
  string input;
  cin>>N>>M>>input;
  for(int i = 0; i < M;i++){
    int cnt = 0;
    if(input[i] == 'I')
      while(i < M-2 && input[i] == 'I' && input[i+1] == 'O' && input[i+2] == 'I'){
        cnt++;
        i += 2;
      }
    if(cnt >= N)res += cnt-N + 1;
  }
  cout<<res;
}