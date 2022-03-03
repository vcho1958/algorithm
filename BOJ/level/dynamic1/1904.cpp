#include <iostream>
#include <vector>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> array(N+1);
  array[1] = 1;
  array[2] = 2;
  for(int i = 3; i <= N; i++){
    array[i] = array[i-1] % 15746 +array[i-2] % 15746;
    array[i] %= 15746;
  }
  cout<< array[N]<<'\n';
  return 0;
}
