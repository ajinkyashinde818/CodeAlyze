#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>

int main(){
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  std::vector<std::vector<char > > A(N, std::vector<char > (N));
  std::vector<std::vector<char > > B(M, std::vector<char > (M));
  for (int i=0; i<N; i++){
    std::string s;
    std::cin >> s;
    for (int j=0; j<N; j++){
      A[i][j]=s[j];
    }
  }
  for (int i=0; i<M; i++){
    std::string s;
    std::cin >> s;
    for (int j=0; j<M; j++){
      B[i][j]=s[j];
    }
  }

  bool ans = false;
  for (int i=0; i<=N-M; i++){
    for (int j=0; j<=N-M; j++){
      bool ok=true;
      for (int k=0; k<M; k++){
        for (int l=0; l<M; l++){
          if (A[k+i][l+j]!=B[k][l]){
            ok=false;
            break;
          }
        }
      }
      ans |= ok;
    }
  }
  printf("%s\n",ans?"Yes":"No");
  return 0;
}
