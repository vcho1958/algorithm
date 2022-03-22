#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int D(int src){
  src *= 2;
  src %= 10000;
  return src;
}

int S(int src){
  src--;
  if(src < 0)src = 9999;
  return src;
}

int L(int src){
  src = src * 10 + src / 1000;
  src %= 10000;
  return src;
}

int R(int src){
  src = src / 10 + (src%10)*1000;
  return src;
}


string BFS(queue<int>& q, vector<string>& answer, vector<bool>& check, int dest){
  while(q.size()){
    while(q.front() != -1){
      int front = q.front();
      q.pop();
      if(!check[D(front)]){
        check[D(front)] = true;
        answer[D(front)] = answer[front] + 'D';
        q.push(D(front));
      }
      if(!check[S(front)]){
        check[S(front)] = true;
        answer[S(front)] = answer[front] + 'S';
        q.push(S(front));
      }
      if(!check[L(front)]){
        check[L(front)] = true;
        answer[L(front)] = answer[front] + 'L';
        q.push(L(front));
      }
      if(!check[R(front)]){
        check[R(front)] = true;
        answer[R(front)] = answer[front] + 'R';
        q.push(R(front));
      }
    }
    if(answer[dest].length())return answer[dest];
    q.pop();
    q.push(-1);
  }
  return "";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin>>T;
  while(T--){
    int src, dest;
    vector<string> answer(10000);
    vector<bool> check(10000, false);
    queue<int> q;
    
    cin>>src>>dest;
    check[src] = true;
    q.push(src);
    q.push(-1);
    cout<<BFS(q, answer, check, dest)<<'\n';
  }

}