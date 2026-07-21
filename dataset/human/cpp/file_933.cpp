#include<bits/stdc++.h>
using namespace std;

int r,g,b,n;

int main(){
  scanf("%d%d%d%d",&r,&g,&b,&n);
  int ans = 0;
  for(int i=0;i<=n/r;i++){
    for(int j=0;j<=n/g;j++){
      int tmp = n-(i*r)-(j*g);
      if(tmp<0 || tmp%b!=0) continue;
      ans++;
//      cout << i << " " << j << " " << tmp/b << endl;
    }
  }
  printf("%d\n",ans);
  return 0;
}
