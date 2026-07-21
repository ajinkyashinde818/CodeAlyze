#include <iostream>
using namespace std;

int main(){
  int a,b,c,n;
  cin >> a >> b >> c >> n;
  int ans=0;
  for(int i=0;i<=3000;i++){
    for(int j=0;j<=3000;j++){
      if(n-a*i-b*j>=0&&(n-a*i-b*j)%c==0){
        ans++;
      }
    }
  }
  cout << ans << endl;
}
