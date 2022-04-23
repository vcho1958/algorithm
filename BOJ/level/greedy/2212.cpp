#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int devide(int K, vector<int> arr, int right, int left = 0){
  int min = arr[right] - arr[left];
  if(K==1)return min;
  int r = right, lvalue, rvalue;
  for(;r > K;r--){
    lvalue = arr[r-1] - arr[left];
    rvalue = arr[right] - arr[r];
    if(min >= lvalue+rvalue) min = lvalue+rvalue;
  }
  int lmin = devide(K-1, arr, r);
  int rmin = devide(K-1, arr, right, r+1);
  int res = lmin < rmin ? lmin : rmin;
  min = res < min ? res : min;
  return min;
}




int main(){
  int N, K;
  cin>>N>>K;
  vector<int> sensors(N);
  for(auto& sensor:sensors)cin>>sensor;
  sort(sensors.begin(), sensors.end());
  cout<<devide(K, sensors, N-1);
}