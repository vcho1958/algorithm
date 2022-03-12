#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> check;
struct cmp{
  bool operator()(string& a, string& b){
      return stoll(a) < stoll(b);
      // if(a[0] == '-' && b[0] == '-')return a > b;
      // if(a[0] == '-')return true;
      // if(b[0] == '-')return false;
      // return a < b;
  }  
};

struct cmp2{
  bool operator()(string& a, string& b){
      return stoll(a) > stoll(b);
      // if(a[0] == '-' && b[0] == '-')return a < b;
      // if(a[0] == '-')return false;
      // if(b[0] == '-')return true;
      // return a > b;
  }  
};

priority_queue<string, vector<string>, cmp> big;
priority_queue<string, vector<string>, cmp2> small;

void insert(string& a){
    if(check.find(a) == check.end())check[a] = 1;
    else check[a]++;
    big.push(a);
    small.push(a);
}

void del(string& a){
    if(small.empty()||big.empty())return;
    string tmp;
    switch(a[0]){
        case '-':
            tmp = small.top();
            small.pop();
            break;
        default:
            tmp = big.top();
            big.pop();
            break;
    }
    check[tmp]--;
}


void clean(){
    
    if(small.size()){
    string smaller = small.top();
    if(check[smaller] == 0)while(small.size() && small.top() == smaller)small.pop();
    }
    if(big.size()){
    string bigger = big.top();
    if(check[bigger] == 0)while(big.size() && big.top() == bigger)big.pop();
        
    }
}
vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    for(auto& operation:operations){
        string number = operation.substr(2);
        switch(operation[0]){
            case 'I':
                insert(number);
                // cout<<big.top()<<' '<<small.top()<<'\n';
                break;
            case 'D':
                del(number);
                // cout<<big.top()<<' '<<small.top()<<'\n';
                clean();
                
        }
    }
    if(big.empty()||small.empty())return answer;
    answer[0] = stoi(big.top());
    answer[1] = stoi(small.top());
    return answer;
}