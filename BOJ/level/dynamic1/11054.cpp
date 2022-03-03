#include <iostream>
#include <vector>


using namespace std;
int main(){
  int N, max = 1;
  cin>>N;
  vector<int> arr(N);
  vector<int> answer(N,1);
  vector<int> answer2(N,1);
  for(auto& a: arr)cin>>a;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < i; j++){
      if(arr[j] < arr[i]){
        if(answer[i] < answer[j] + 1)answer[i] = answer[j] + 1;
        }
    }
  }
  for(int i = N-1; i>=0; i--){
    for(int j = N-1; j > i; j--){
      if(arr[j] < arr[i]){
        if(answer2[i] < answer2[j] + 1)answer2[i] = answer2[j] + 1;
      }
    }
    if(answer[i] + answer2[i] - 1 > max)max = answer[i] + answer2[i] - 1;
  }

  cout<<max<<'\n';
  return 0;
}