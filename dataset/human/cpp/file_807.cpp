#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  int just_count=0;
  for (int i=0;i*R<=N;i++){
    for (int j=0;j*G<=N;j++){
      int remainder=i*R+j*G;
      if ((N-remainder)%B==0 && N-remainder>=0){
        just_count++;
      }
    }
  }
  cout << just_count << endl;
}
