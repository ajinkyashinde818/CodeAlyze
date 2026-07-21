#include<stdio.h>
int main(){
  int n,d[100][100]={0};
  int i,j,max=-1000000000,k,l,p,q,s;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d",&d[i][j]);
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;i+k<n;k++){
	s=0;
	for(l=0;j+l<n;l++){ 
	  for(p=0;p<=k;p++){
	    s+=d[i+p][j+l];
	  }
	  if(max<s)max=s;
	}
      }
    }
  }
  printf("%d\n",max);
  return 0;
}
