#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> V;
  int64_t y=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    V.push_back(a);
    y+=a;
  }
  int64_t ans=1LL<<60;
  int64_t x=0;
  for(int i=0;i<N-1;i++){
    x+=V[i];
    y-=V[i];
    ans=min(ans,abs(x-y));
  }
  cout<<ans<<endl;
  return 0;
}
