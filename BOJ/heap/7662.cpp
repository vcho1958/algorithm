#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main() {
  int T;
  cin>>T;
  while(T--){
    int k;
    cin>>k;
    map<int, int> q;
    for(int i = 0; i < k; i++){
        string op;
        int number;
        cin>>op>>number;
        switch(op[0]){
            case 'I':
              if(q.find(number) == q.end())q[number] = 1;
              else q[number]++;
              break;
            case 'D':
              if(q.empty())continue;
              auto rbegin = q.end();
              rbegin--;
              auto begin = q.begin();
              if(number == 1){
                rbegin->second--;
                if(rbegin->second == 0)q.erase(rbegin);
              }else{
                begin->second--;
                if(begin->second ==0)q.erase(begin);
              }
        }
    }
    if(q.empty())cout<<"EMPTY\n";
    else cout<<q.rbegin()->first << ' '<<  q.begin()->first<<'\n';
  }
}