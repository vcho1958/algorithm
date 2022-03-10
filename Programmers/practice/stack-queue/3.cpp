#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, remainWeight = weight, cursor = 0;
    queue<int> bridge;
    for(int i = 0; i < bridge_length; i++)bridge.push(0);
    while(cursor < truck_weights.size()){
        answer++;
        remainWeight += bridge.front();
        bridge.pop();
        if(remainWeight >= truck_weights[cursor]){
            remainWeight -= truck_weights[cursor];
            bridge.push(truck_weights[cursor++]);
        }else bridge.push(0);
    }
    while(remainWeight != weight){
                answer++;
        remainWeight += bridge.front();
        bridge.pop();
    }
    return answer;
}