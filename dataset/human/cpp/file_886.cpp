#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
  int R,G,B,N;
  int r,g,b;
  int ansflg=0;
  int cnt=0;
  int tmp;

  cin >> R >> G >> B >> N;

  r = N/R;
  g = N/G;
  b = N/B;

  for(int i=0; i<=r; i++){
    for(int j=0; j<=g; j++){
      tmp = N-i*R-j*G;
      if(tmp%B==0 &&tmp >=0){
          cnt++;
          //          cout <<"i= " <<i <<"j= "<<j <<"k= " << tmp/B <<   " cnt = " << cnt <<endl; 
      }
    }
  }
  
    cout << cnt << endl;
}
