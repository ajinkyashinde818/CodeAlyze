#include<stdio.h>
#include<stdlib.h>
char d[90][90][6500]={};
int main(){
  int h,w,i,j,k,a[100][100];
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)scanf("%d",&a[i][j]);
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      scanf("%d",&k);
      a[i][j]=abs(a[i][j]-k);
    }
  }
  d[0][0][a[0][0]]=1;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      for(k=0;k<6410;k++){
	if(d[i][j][k]==0)continue;
	if(i+1<h){
	  d[i+1][j][    k+a[i+1][j] ]=1;
	  d[i+1][j][abs(k-a[i+1][j])]=1;
	}
	if(j+1<w){
	  d[i][j+1][    k+a[i][j+1] ]=1;
	  d[i][j+1][abs(k-a[i][j+1])]=1;
	}
      }
    }
  }
  for(i=0;i<6410;i++){
    if(d[h-1][w-1][i]==0)continue;
    printf("%d\n",i);
    return 0;
  }
}
