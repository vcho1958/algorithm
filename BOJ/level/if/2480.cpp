#include <iostream>
#include <vector>
using namespace std;

int main(){
  int max_count = 0, max_index = -1;
  vector<int> scores(6,0);
  for(int i = 0; i < 3; i++){
    int input;
    cin>>input;
    scores[input-1]++;
    if(scores[input-1] == max_count) {
      if(max_index < input-1)max_index = input-1;
    }
    if(scores[input-1] > max_count){
      max_index = input-1;
      max_count = scores[input-1];
    }
  }
  int score;
  switch (max_count)
  {
  case 1:
    score = (max_index + 1)*100;
    break;
  case 2:
    score = (max_index + 1)*100 + 1000;
    break;
  case 3:
    score = (max_index + 1)*1000 + 10000;
    break;
  }
  cout<<score<<'\n';
}