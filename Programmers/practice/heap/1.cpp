#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> scoville2;
    for(auto& s:scoville)scoville2.push(s);
    while(scoville2.size() > 1){
        answer++;
        int s = scoville2.top();
        scoville2.pop();
        s+=scoville2.top()*2;
        scoville2.pop();
        scoville2.push(s);
        if(scoville2.top() >= K)return answer;
    }
    return -1;
}