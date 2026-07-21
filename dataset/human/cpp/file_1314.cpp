#include<bits/stdc++.h>
using namespace std;

int main (void){
  int R,G,B,N,a,ans = 0;
  cin >> R >> B >> G >> N;
  
  
  for(int i = 0; i*R <= N; i++){
    for(int j = 0; i*R+j*G <= N; j++){
      a = R*i + G*j;
        if((N-a) % B == 0 && N >= a){
          ans++;
        }
      }
  }
  
  cout << ans << "\n";
  return 0;
}
