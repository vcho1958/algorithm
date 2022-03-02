#include <iostream>
int fib0(int *narr, int n){
    if(narr[n] != -1)return narr[n];
    for(int i = 2; i <= n; i++){
      if(narr[i] != -1)continue;
      narr[i] = narr[i-2] + narr[i-1];
    }
    return narr[n];
}
int fib1(int *narr, int n){
  if(narr[n] != -1)return narr[n];
  for(int i = 2; i <= n; i++){
    if(narr[i] != -1)continue;
    narr[i] = narr[i-2] + narr[i-1];
  }  
  return narr[n];
}

int main(){
  std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
  int T, N, narr0[41] = {1, 0}, narr1[41] = {0, 1};
  for(int i = 2; i < 41; i++){
    narr0[i] = -1;
    narr1[i] = -1;
  }
  std::cin>>T;
  for(int i = 0; i < T; i++){
      std::cin>>N;
      std::cout<<fib0(narr0, N)<<' '<<fib1(narr1, N)<<'\n';
  }

}