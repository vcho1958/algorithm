#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
  string first, second;
  cin >> first >> second;
  vector<int> answer(first.size(), 0);
  int f = 0, s = 0,count = 0;
  for(; f < first.size(); f++){
    for(; s < second.size(); s++){
      if(first[f] == second[s])second = ++count;
    }
  }
}