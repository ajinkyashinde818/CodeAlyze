#include<stdio.h>
int main(){
  int i,j;
  int c[8],l[8]={1,4,1,4,1,2,1,2},n,m,max;
  while(scanf("%d%d%d%d%d%d%d%d",&c[0],&c[1],&c[2],&c[3],&c[4],&c[5],&c[6],&c[7])!=-1){
    max=0;
    m=0;
    for(i=0;i<8;i++){
      n=0;
      for(j=0;j<8;j++)
	n+=l[(i+j)%8]<c[j]?l[(i+j)%8]:c[j];
      if(max<n){
	max=n;
	m=i;
      }else if(max==n){
	for(j=0;j<8;j++){
	  if(l[(m+j)%8]>l[(i+j)%8]){
	    m=i;
	    break;
	  }else if(l[(m+j)%8]<l[(i+j)%8])
	    break;
	}
      }
    }
    for(i=0;i<8-1;i++)
      printf("%d ",l[(m+i)%8]);
    printf("%d\n",l[(m+i)%8]);
  }
  return 0;
}
