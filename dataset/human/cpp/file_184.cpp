#include <bits/stdc++.h>

using namespace std;

int main() {
  int R,G,B,N;

  cin >> R >> G >> B >> N;

  int count = 0;

  for(int r=0; r<=N; r++){
    int sum1 = 0;
    sum1 += R*r;
    if(sum1 < N){
      for(int g=0; g<=N; g++){
        int sum2 = sum1 + G*g;
        if(sum2 < N){
          if((N-sum2)%B == 0){
            count++;
          }
        }else if(sum2 == N){
          count++;
          break;
        }else if(sum2 > N){
          break;
        }
      }
    }else if(sum1 == N){
      count++;
      break;
    }else if(sum1 > N){
      break;
    }
  }

  cout << count;


  return 0;
}
