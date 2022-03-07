#include<iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> array(N), sorted(N);
  vector<int> answer(N);
  map<int,int> rank;
  for(int i = 0; i < N; i++){
    int a;
    cin>>a;
    array[i] = a;
    sorted[i] = a;
  }
  sort(sorted.begin(), sorted.end());
  for(int i = 0; i < N; i++){
    if(rank.size() && rank.find(sorted[i]) != rank.end())continue;
    rank[sorted[i]] = rank.size();
  }
  for(int i = 0; i < N; i++){
    answer[i] = rank[array[i]];
  }

  for(auto a:answer)cout<<a<<' ';

}