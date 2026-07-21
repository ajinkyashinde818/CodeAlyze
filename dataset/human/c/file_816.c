#include<stdio.h>
int main(void){
int D,G,res=1<<30;
  scanf("%d %d",&D,&G);
  int p[D],c[D];
  for(int i=0;i<D;i++){
    scanf("%d %d",&p[i],&c[i]);
  }
int i,j;
  for(i=0;i<(1<<D);i++){
    int sum=0;
    int cnt=0;
   // printf("%dパターン目\n",i+1);
    for(j=0;j<D;j++){
      
      if(i&(1<<j)){
        sum+=100*(j+1)*p[j]+c[j];    //そのパターンにおける合計スコア
        cnt+=p[j];					//そのパターンにおける解いた問題数
      }
    }
      if(sum>=G){
        if(res>cnt)res=cnt;    //最小値の更新
      }
      else{
        for(int j=D-1;j>=0;j--){//高得点問題から優先的に解く
          
          if(i&(1<<j)) continue;//全完済みの問題をスキップ
          for(int k=0;k<p[j];k++){
            if(sum>=G)break;
          sum+=100*(j+1);
          cnt++;
          }
        }
        
       if(res>cnt)res=cnt;
      }
    
    
  }
    printf("%d",res);
  }
