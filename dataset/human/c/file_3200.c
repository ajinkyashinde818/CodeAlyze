#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define BUFSIZE 1000000


int dis[BUFSIZE]={0};
int N,K;
int cal(int start_pos){
  if(start_pos == N + 1)
    return 0;
  if(start_pos == 1 ){
    if(dis[N-1] - dis[0] > K - (dis[1] - dis[0]))
       return K - (dis[1] - dis[0]);
    else  return  dis[N-1] - dis[0];
  }
  if(start_pos == N){
    if(dis[N-1] - dis[0] > K - (dis[N-1] - dis[N-2]))
       return K - (dis[N-1] - dis[N-2]);
    else  return  dis[N-1] - dis[0];
  }





  if(dis[start_pos - 1] + dis[start_pos + 1] > dis[start_pos]*2 )
      return (K - (dis[start_pos + 1] - dis[start_pos]));
  else  return (K - (dis[start_pos] - dis[start_pos - 1]));

  cal(start_pos + 1);
}


int main(void){
  scanf("%d %d",&K,&N);

  for(int i = 0 ; i < N ; i++){
    scanf("%d",&dis[i]);
  }
  int answer = cal(1);
  for(int i = 1 ; i <= N ; i++) {
      if(answer >= cal(i)){

          answer = cal(i);
      }
  }
  printf(" %d",answer);
}
