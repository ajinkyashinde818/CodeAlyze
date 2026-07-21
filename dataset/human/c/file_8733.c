#include <stdio.h>
int main(){
  int N, i, j, cnt=1;
  scanf("%d", &N);
  int arr[N];
  for (i=0; i<N; i++) {
    scanf("%d", &arr[i]);
  }
  i=0;
  while(cnt<N+1){
    j=arr[i];
    if (j==2) {
      printf("%d\n", cnt);
      break;
    } else {
      i=j-1;
      cnt++;
      if (cnt>=N) {
        printf("%d\n", -1);
        break;
      }
    } 
  }
  return 0;
}
