#include <stdio.h>

int h;
int memo[11][5];
int bf,ans;


int main(){
  int i,j,k;
  while(1){
    scanf("%d",&h);
    if(h==0)break;
    bf=-1;
    ans=0;
    for(i=0;i<h;i++)for(j=0;j<5;j++)scanf("%d",&memo[i][j]);
    while(ans!=bf){
      bf = ans;
      //消す作業
      for(i=0;i<h;i++)for(j=0;j<3;j++){
	  int now=j;
	  while(memo[i][now]==memo[i][j]&&j<5)j++;
	  if(j-now>=3&&memo[i][now]!=-1){
	    ans+=(j-now)*memo[i][now];
	    for(k=now;k<j;k++)memo[i][k]=-1;
	  }
	  j--;
	}
      //落とす作業
      for(j=0;j<5;j++)for(i=h-1;i>=0;i--){
	  int now=i;
	  while(memo[i][j]==-1&&i>=0)i--;
	  if(i>=0&&now!=i){
	    memo[now][j]=memo[i][j];
	    memo[i][j]=-1;
	    i=now;
	  }
	}
      /*for(i=0;i<h;i++){
	for(j=0;j<5;j++)printf("%d ",memo[i][j]);
	printf("\n");
      }
      printf("\n");*/
    }
    printf("%d\n",ans);
    
  }
  return 0;
}
