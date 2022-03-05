#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;






int main(){
  int N;
  long long answer = 0;
  cin>>N;
  vector<long long> distances(N-1);
  for(auto& d: distances)cin>>d;
  
  vector<long long> nodes(N);
  for(auto& n:nodes)cin>>n;
  for(int i = 0; i < N-1;){
    long long cost = nodes[i];
    while(i < N-1 && nodes[i] >= cost){
      answer += distances[i] * cost;
      i++;
    }
  }
  cout<<answer<<'\n';

}