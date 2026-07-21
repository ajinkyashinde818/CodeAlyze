#include <bits/stdc++.h>
using namespace std;

int main() {
  int R,G,B,N;
  scanf("%d %d %d %d", &R,&G,&B,&N);

  vector<int> v{R,G,B};

  sort(v.begin(),v.end());

  int one = N/v[2];
  int two = N/v[1];
  int count = 0;

  for(int i=0;i<one+1;++i){
    for(int j=0;j<two+1;++j){
      if((N-(i*v[2]+j*v[1]))%v[0] == 0 && i*v[2]+j*v[1]<=N){
        ++count;
      }
    }
  }

  cout << count << endl;

}
