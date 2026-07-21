#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t>data(N);
  int count=0;
  for(int i=0;i<N;i++){
    cin >> data.at(i);
    if(data.at(i)<0) count++;
    data.at(i)=abs(data.at(i));
  }
  int64_t ans=0;
  if(count%2==0){
    for(int i=0;i<N;i++){
      ans+=data.at(i);
    }
  }
  else{
    sort(data.begin(),data.end());
    ans-=data.at(0);
    for(int i=1;i<N;i++){
      ans+=data.at(i);
    }
  }
  cout << ans << endl;
}
