#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;



bool isPhoneExists(string& phone, map<string, int>& book){
    string tmp = "";
    for(auto number:phone){
        tmp += number;
        if(book.find(tmp) != book.end())
            return true;
    }
    return false;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> book;
    sort(phone_book.begin(), phone_book.end());
    for(string phone: phone_book){
        if(isPhoneExists(phone, book))return false;
        book[phone] = 1;
    }
    return true;
}