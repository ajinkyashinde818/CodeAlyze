#include<stdio.h>

int num[10][5];
int H;

int puzzle(int i,int j,int k){
  int p;
  num[i][j]=0;
  if((j+1)<5&&(num[i][j+1]==k)) p=puzzle(i,j+1,k)+k;
  else p=k;
  return p;
}

int main(){
  int ans;
  int i,j,k;
  int flag=0;

  while(scanf("%d",&H),H!=0){
    ans=0;
    for(i=H-1;i>=0;i--){
      for(j=0;j<5;j++){
	scanf("%d",&num[i][j]);
      }
    }
    flag=1;
    while(flag==1){
      flag=0;
      for(i=0;i<H;i++){
	for(j=0;j<3;j++){
	  if(num[i][j]!=0&&((num[i][j]==num[i][j+1])&&(num[i][j+1]==num[i][j+2]))){
	    ans+=puzzle(i,j,num[i][j]);
	    flag=1;
	  }
	}
      }
      for(i=H-1;i>0;i--){
	for(j=0;j<5;j++){
	  if(num[i-1][j]==0){
	    for(k=i-1;k<H-1;k++){
	      num[k][j]=num[k+1][j];
	    }
	    num[H-1][j]=0;
	  }
	}
      }
    }
    printf("%d\n",ans);
  }

  return 0;
}
