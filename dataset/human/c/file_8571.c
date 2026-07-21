#include <stdio.h>

int main(){
  int N;
  int arr[100000];
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&arr[i]);
  }
  int cnt=0;
  for(int pointer=0;pointer!=1;pointer=arr[pointer]-1){
    cnt++;
    if(cnt>100005) {cnt=-1; break;}
  }
  printf("%d",cnt);
}
