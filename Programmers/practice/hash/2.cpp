#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> closet;
    
    for(auto& cloth:clothes){
        if(closet.find(cloth[1])== closet.end())closet[cloth[1]] = 2;
        else closet[cloth[1]]++;
    }
    
    for(auto& kindOf: closet)answer *= kindOf.second;
    return answer-1;
}