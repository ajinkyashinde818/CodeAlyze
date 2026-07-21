#include <stdio.h>

int main(){
  int N;
  int a[100010] = {};
  int i;
  int count = 0;
  scanf("%d", &N);
  for(i = 1; i <= N; i++){
    scanf("%d", &a[i]);
  }
  i = 1;
  while(i != 2){
    i = a[i];
    count++;
    if(count > N){
      //光るボタンはN+1回目までに元に戻る
      printf("-1\n");
      return 0;
    }
  }
  printf("%d\n", count);
  return 0;
}
