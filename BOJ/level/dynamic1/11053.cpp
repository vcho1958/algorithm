#include <iostream>
#include <vector>


using namespace std;
int main(){
  int N, max = 0;
  cin>>N;
  vector<int> arr(N);
  vector<int> answer(N,1);
  for(auto& a: arr)cin>>a;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < i; j++){
      if(arr[j] < arr[i]){
        if(answer[i] < answer[j] + 1)answer[i] = answer[j] + 1;
        }
    }
    if(answer[i] > max)max = answer[i];
  }
  cout<<max<<'\n';
  return 0;
}