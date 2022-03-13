#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N, maxv = -4000, minv = 4000, sum = 0;
  cin>>N;
  vector<int> kind(8001,0);
  vector<int> data(N);
  for(auto& d:data){
    cin>>d;
    sum += d;
    kind[d+4000]++;
    if(maxv < d)maxv = d;
    if(minv > d)minv =d;
  }
  int average;
  if(sum >= 0) average = sum % N > N/2 ? (sum / N) + 1 : sum / N;
  else average = -(sum % N) > N/2 ? (sum / N) - 1 : sum / N;
  sort(data.begin(), data.end());
  cout<<average<<'\n';
  cout<<data[N/2]<<'\n';
  int max = 0, max2 = -1;
  for(int i = 1; i < 8001;i++)
  if(kind[i])
    if(kind[max] < kind[i]){
      max = i;
      max2 = -1;
    }else if(kind[max] == kind[i] && max2 == -1){
      max2 = max;
      max = i;
    }
  cout<<max-4000<<'\n';
  cout<<maxv-minv<<'\n';


}