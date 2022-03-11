#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

struct cmp{
    bool operator()(tuple<int,int,int>&a, tuple<int,int,int>&b){
        if(get<1>(a) > get<1>(b))return true;
        else if(get<1>(a) == get<1>(b) && get<2>(a) > get<2>(b))return true;
        return false;
    }
};


int solution(vector<vector<int>> jobs) {
    int answer = 0, next = 0;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, cmp> q;
    for(auto& job:jobs)q.push(make_tuple(job[0],job[0],job[1]));
    while(q.size()){
        int next = get<1>(q.top()) + get<2>(q.top());
        answer += next - get<0>(q.top());
        cout<<answer<<' ';
        q.pop();
        while(q.size() && get<1>(q.top()) < next){
            tuple<int,int,int> job = q.top();
            get<1>(job) = next;
            q.pop();
            q.push(job);
        }
    }
    return answer/jobs.size();
}