#include<iostream>

using namespace std;
int main(){
  int A, B, C;
  cin>>A>>B>>C;
  cout<< (A+C/60 + (B+C%60)/60)%24 <<' '<< (B+ C%60)%60<<'\n';
}