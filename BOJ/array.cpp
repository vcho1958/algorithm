#include <iostream>
#include <vector>

using namespace std;



int devide(int K, int N, vector<int> arr){
  int min = arr[N] - arr[0];
  if(K==1)return min;
  int r = N;
  for(;r > K;r--){
    int lvalue = arr[r-1] - arr[0];
    int rvalue = arr[N] - arr[r];
    if(min >= lvalue+rvalue) min = lvalue+rvalue;
    else {break;}
  }
  int res = devide(K-1, r, arr);
  min = res < min ? res : min;
  return min;
}

int main(){
  int N, K;
  cin >> N;
  cin >> K;
  vector<int> arr(N);
  for(auto& a: arr)cin>>a;
  cout<<devide(K, N-1, arr);
}
