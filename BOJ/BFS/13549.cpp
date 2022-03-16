#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int getTime(queue<int>& bfs, vector<bool>& check, int N, int K){
  int res = 0, maxTime = K-N;
  while(bfs.size()){
    if(bfs.front() == -1)break;
    while(bfs.front() != -1){
      int front = bfs.front();
      for(int i = front; i < check.size();i*=2){
        if(i == K)return res;  
        if(i > 0 && !check[i-1]){
          bfs.push(i-1);
          check[i-1] = true;
        }
        if(i < 100001 && !check[i+1]){
          bfs.push(i+1);
          check[i+1] = true;
        }
      }
      bfs.pop();
    }
    bfs.pop();
    res++;
    bfs.push(-1);
  }
  return res;
}


int main(){
  int N,K;
  cin>>N>>K;
  queue<int> bfs;
  vector<bool> check(K+K-N+1, false);
  bfs.push(N);
  bfs.push(-1);
  cout<<getTime(bfs,check, N, K)<<'\n';
}