#include<iostream>
#include<deque>
#include<string>
using namespace std;


int main(){
  int T;
  cin>>T;
  while(T--){
    string macro, arrayString, chunk;
    deque<string> d;
    int N;
    bool isReverse = false, isError = false;
    cin>>macro>>N>>arrayString;
    for(auto integer:arrayString){
      if(integer == '[' )continue;
      if(integer == ','|| integer == ']'){
        if(chunk != "")d.push_back(chunk);
        chunk = "";
      }
      else chunk += integer;
    }
    for(auto m:macro){
      if(m == 'R')isReverse = !isReverse;
      else if(m == 'D'){
        if(d.empty())isError = true;
        else if(isReverse)d.pop_back();
        else if(!isReverse)d.pop_front();
      }
    }
    if(isError)cout<<"error"<<'\n';
    else{
      cout<<'[';
      if(isReverse){
        for(auto iter = d.rbegin(); iter != d.rend(); iter++){
          cout<<*iter;
          if(iter+1 != d.rend())cout<<',';
        }
      }else{
        for(auto iter = d.begin(); iter != d.end(); iter++){
          cout<<*iter;
          if(iter+1 != d.end())cout<<',';
        }
      }
      cout<<']'<<'\n';
    }
    
  }
}