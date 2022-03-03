#include<iostream>
#include<vector>


using namespace std;

inline int max(vector<int> arr, int n){
  int max = 0;
  for(auto a: arr)if(max < a)max = a;
  return max;
};

int main(){
  
  int N;
  cin>>N;
  vector<int> cups(N);
  for(int i = 0; i < N; i++)cin>>cups[i];
  vector<vector<int>> answers(N,vector<int>(3, 0));
  answers[0][0] = 0; 
  answers[0][1] = cups[0];
  answers[0][2] = cups[0];


  for(int i = 1; i < N; i++){
    answers[i][0] = max(answers[i-1],3);
    answers[i][1] = answers[i-1][0] + cups[i];
    answers[i][2] = answers[i-1][1] + cups[i];
  }
  cout<< max(answers[N-1], 3) <<'\n';
  return 0;
}