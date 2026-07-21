#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> cs(N+1);
  cs.at(0)=0;
  int64_t sum=0;
  for(int i=1;i<=N;i++){
    int64_t a;
    cin >> a;
    cs.at(i)=cs.at(i-1)+a;
    sum+=a;
  }
  priority_queue< int64_t,vector<int64_t>,greater<int64_t> >pq;
  for(int i=1;i<N;i++){
    pq.push(abs(sum-2*cs.at(i)));
  }
  cout << pq.top() << endl;
  return 0;
}
