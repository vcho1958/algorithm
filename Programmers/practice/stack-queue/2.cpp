#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct cmp{
  bool operator()(pair<int,int>& a, pair<int,int>& b){
      if(a.first < b.first)return true;
      if(a.first == b.first && a.second > b.second)return true;
      return false;
  }  
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int,int>> d;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> a;
    for(int i = 0; i < priorities.size(); i++){
        a.push(make_pair(priorities[i], i));
        d.push_back(make_pair(priorities[i], i));
    }
    while(d.size()){
        while(d.front().first != a.top().first){
            d.push_back(d.front());
            d.pop_front();
        }
        answer++;
        if(d.front().second == location)return answer;
        a.pop();
        d.pop_front();
    }
    return answer;
}