#include <string>
#include <vector>
#include <deque>
using namespace std;

int progress(deque<int>& tmp){
    int res = 0;
    while(*tmp.begin() > 0)for(auto& t:tmp)t--;
    while(tmp.size() && *tmp.begin() <= 0){
        tmp.pop_front();
        res++;
    }
    return res;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> tmp;
    for(int i = 0; i < progresses.size();i++){
        if((100-progresses[i])%speeds[i])
            tmp.push_back((100-progresses[i])/speeds[i] + 1);
        else tmp.push_back((100-progresses[i])/speeds[i]);
    }
    
    while(tmp.begin() != tmp.end()){
        answer.push_back(progress(tmp));
    }
    
    return answer;
}