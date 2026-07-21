#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int N;
  cin >> N;
  int count = 0;
  bool inzero=false;
  long long ans = 0;
  int ln = (int)1e9;
  vector<int> line(N);
  for(int i=0;i<N;++i){
    cin>>line[i];
    if(line[i] < 0){
      ++count;
    }
    if(line[i]==0)inzero=true;
    ans += abs(line[i]);
    ln = min(ln,abs(line[i]));
  }
  if(inzero || (count % 2 == 0)){
    cout << ans << endl;
  }else{
    cout << ans - ln * 2 << endl;
  }
  return 0;
}
