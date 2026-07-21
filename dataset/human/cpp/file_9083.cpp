#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;

  vector<string> image(N);
  vector<string> piece(M);
  for(int i=0; i<N; i++){
    cin >> image.at(i);
  }
  for(int i=0; i<M; i++){
    cin >> piece.at(i);
  }

  for(int i1=0; i1<=N-M; i1++){
    for(int i2=0; i2<=N-M; i2++){
      bool is_matched= true;
      for(int t1=0; t1<M; t1++){
        for(int t2=0; t2<M; t2++){
          if(image.at(i1+ t1).at(i2+ t2)!=piece.at(t1).at(t2)){
            is_matched= false;
            break;
          }
        }
        if(!is_matched) break;
      }

      if(is_matched){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
