#include<iostream>
#include<queue>
int main(){
  std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
  int height, htmp,wtmp, a ,P, width, T, wmax = 0, hmax = 0;
  std::priority_queue<int> hpoint, wpoint;
  std::cin>>height;
  std::cin>>width;
  hpoint.push(0);
  wpoint.push(0);
  hpoint.push(height);
  wpoint.push(width);
  std::cin>>T;
  for(int i = 0, hmax = 0, wmax = 0; i < T; i++){
    std::cin>>a;
    std::cin>>P;
    if(a)hpoint.push(P);
    else wpoint.push(P);
  }
  for(; wpoint.size();){
    wtmp = wpoint.top();
    wpoint.pop();
    if((wtmp - wpoint.top()) >= wmax)wmax = wtmp - wpoint.top();
  }
  for(; hpoint.size();){
    htmp = hpoint.top();
    hpoint.pop();
    if((htmp - hpoint.top()) >= hmax)hmax = htmp - hpoint.top();
  }
  std::cout<<wmax*hmax<<'\n';


}  
