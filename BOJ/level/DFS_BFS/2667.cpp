#include<iostream>
#include<vector>
using namespace std;

int check(vector<vector<int>>& map, int i, int j){
  int count = 1;
  if(map[i][j])map[i][j] = 0;
  if(map[i][j+1])count += check(map, i, j+1);
  if(map[i-1][j])count += check(map, i-1, j);
  if(map[i+1][j])count += check(map, i+1, j);
  if(map[i][j-1])count += check(map,i,j-1);
  return count;
}



int main(){
  int N, count = 0;
  cin >> N;
  vector<vector<int>> map(N, vector<int>(N));
  vector<int> house;
  for(auto& row: map)for(auto& point:row)cin>>point;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(map[i][j]){
        house.push_back(check(map,i,j));
        count++;
      }
    }
  }
  cout<<count<<'\n';
  for(auto h:house)cout<<h<<'\n';

}