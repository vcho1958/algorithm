#include <iostream>
#include <vector>


using namespace std;
int main(){
  int N,K, answer = 0;
  cin >> N >> K;
  vector<int> coins(N);
  for(auto& coin:coins)cin>>coin;
  for(int i = N-1; i >=0 && K; i--){
    if(coins[i] > K)continue;
    answer += K/coins[i];
    K -= coins[i] * (K/coins[i]);
  }
  cout<<answer<< '\n';
}