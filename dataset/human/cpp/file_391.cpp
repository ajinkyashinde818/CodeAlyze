#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[5][5];
int main(){
  int r, g, b, n, cnt=0;
    cin >> r >> g >> b >> n;
    for(int i=0; i<=n; i++){
      for(int j=0; r*i+g*j<=n; j++){
        int k = n - (r*i+g*j);
        //cout << k << endl;
        if(k%b==0 && 0<=k){
          cnt += 1;
          //cout << i << j << k << endl;
        }
      }
    }
    cout << cnt << endl;
}
