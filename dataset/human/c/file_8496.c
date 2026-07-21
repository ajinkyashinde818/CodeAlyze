#include<stdio.h>
int main(){
  int h,i,j,p,k,l,c;
  while(scanf("%d",&h),h){
    int d[15][7]={0};
    for(i=p=0;i<h;i++){
      for(j=0;j<5;j++)scanf("%d",&d[h-i-1][j]);
    }
    for(l=0;l<20;l++){
      for(i=0;i<h;i++){
	c=1;
	for(j=0;j<5;j++){
	  if(d[i][j]==d[i][j+1])c++;
	  else{
	    if(c>2){
	      p+=c*d[i][j];
	      for(k=j-c+1;k<=j;k++)d[i][k]=0;
	    }
	    c=1;
	  }
	}
      }
      for(j=0;j<5;j++){
	for(i=c=0;i<h;i++){
	  d[i-c][j]=d[i][j];
	  if(d[i][j]==0)c++;
	}
	for(i=h-c;i<h;i++)d[i][j]=0;
      }
    }
    printf("%d\n",p);
  }
  return 0;
}
