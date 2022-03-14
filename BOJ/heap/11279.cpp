#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>


using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin>>N;
  priority_queue<int, vector<int>, less<int>> q;
  while(N--){
    int number;
    cin>>number;
    if(number)q.push(number);
    else{
      if(q.size()){
        cout<<q.top()<<'\n';
        q.pop();
      }
      else cout<<0<<'\n';
    }
  }
}