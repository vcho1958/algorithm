#include<set>
#include<iostream>
#include<string>

using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int M;
  cin>>M;
  set<int> s;
  while(M--){
    string op;
    int N;
    cin>>op;
    if(op == "all")for(int i = 1; i <= 20; i++)s.insert(i);
    else if(op == "empty")s.clear();
    else{
      int N;
      cin>>N;
      if(op == "add")s.insert(N);
      else if(op == "remove")s.erase(N);
      else if(op == "check")cout << int(s.find(N) != s.end()) << '\n';
      else if(op == "toggle")if(s.find(N) == s.end())s.insert(N); else s.erase(N);
    }

  }
}