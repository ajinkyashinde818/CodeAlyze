#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  long long result=0;
  long long absmin=1e9;
  int cntminus=1;
  for(int i=0; i<N; i++){
    long long a; cin >> a;
    if(a>0){
      cntminus*=1;
    }else if(a==0){
      cntminus*=0;
    }else{
      cntminus*=(-1);
    }
    a=(a>0?a:-a);
    result+=a;
    absmin=(absmin<a?absmin:a);
  }
  if(cntminus==-1){
    cout << result - 2 * absmin << endl;
  }else{
    cout << result << endl;
  }
}
