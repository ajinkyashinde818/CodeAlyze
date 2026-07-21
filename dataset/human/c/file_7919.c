#include<stdio.h>
#include<stdbool.h>

void solve(int n);

int main(void){
  int n;
  while(scanf("%d",&n) && n)  solve(n);
  return 0;
}

void solve(int n){
  int bridge[20][20]={{0}};
  int count[20]={0},time[20]={0};
  bool flg[20];
  int i,j,k,t,rest,next,tmp;
  int sum=0,is1,is2;

  for(i=0;i<n-1;i++){
    scanf("%d%d%d",&is1,&is2,&t);
    is1--;
    is2--;
    bridge[is1][is2]=bridge[is2][is1]=t;
    sum+=2*t;
    count[is1]++;
    count[is2]++;
  }

  for(i=1;i<n;i++){
    time[i]=500000;
    flg[i]=false;
  }
  flg[0]=true;

  for(i=0,rest=n-1;rest>0;i=next,rest--){
    for(j=0;j<n;j++){
      if(bridge[i][j]==0) continue;
      tmp=bridge[i][j]+time[i];
      if(tmp<time[j]) time[j]=tmp;
    }

    for(j=0,next=-1;j<n;j++){
      if(flg[j]) continue;
      if(next==-1 || time[j]<time[next]) next=j;
    }
    flg[next]=true;
  }

  for(i=1;i<n;i++){
    if(count[i]==1){
      for(j=0;j<n && bridge[i][j]==0;j++);
      sum-=2*bridge[i][j];
      time[i]=0;
    }
  }

  for(tmp=time[0],i=0;i<n;i++) if(tmp<time[i]) tmp=time[i];
  sum-=tmp;
  printf("%d\n",sum);
}
