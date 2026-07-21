#include <stdio.h>

int main(){
  int N;
  scanf("%d",&N);

  int A[N];
  for (int i=0; i<N; i++) {
    scanf("%d",&A[i]);
  }

  int B[N],mCon = 0;
  long ans = 0,min = 1000000000;
  for (int j=0; j<N; j++) {
    if (A[j] < 0) {
      B[j] = A[j]*(-1);
      mCon++;
    } else {
      B[j] = A[j];
    }
    ans += B[j];
    if (min > B[j]) {
      min = B[j];
    }
  }

  if (mCon%2 == 1) {
    ans = ans - min*2;
  }

printf("%ld\n",ans);
return 0;
}
