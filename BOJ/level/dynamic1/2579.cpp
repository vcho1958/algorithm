#include<iostream>
#include<vector>


using namespace std;

inline int max(int a, int b){return a > b? a : b;};

int main(){
  int N;
  cin>>N;
  vector<int> stairs(N);
  for(int i = 0; i < N; i++)cin>>stairs[i];
  vector<vector<int>> answers(N,vector<int>(2, 0));
  answers[0][0] = stairs[0]; 
  answers[0][1] = stairs[0];
  if(N>1){
    answers[1][0] = stairs[1];
    answers[1][1] = answers[0][1]+stairs[1];
  }

  for(int i = 2; i < N; i++){
    answers[i][0] = max(answers[i-2][1] + stairs[i], answers[i-2][0] + stairs[i]);
    answers[i][1] = answers[i-1][0] + stairs[i];
  }
  cout<< max(answers[N-1][0], answers[N-1][1])<<'\n';
  return 0;
}