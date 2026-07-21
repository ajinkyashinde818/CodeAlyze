#include<stdio.h>
int main(){
  int k[8],i,j,min,w,s;
  int m[15]={1,2,1,2,1,4,1,4,1,2,1,2,1,4,1};
  int h[8]={1,5,2,6,4,8,3,7};
  while(scanf("%d %d %d %d %d %d %d %d",
   &k[0],&k[1],&k[2],&k[3],&k[4],&k[5],&k[6],&k[7])!=EOF){
    min=1000000000;
    for(i=0;i<8;i++){
      w=0;
      for(j=0;j<8;j++){
	if(k[j]-m[i+j]>0){
	  w+=k[j]-m[i+j];
	}
      }
      if(min>w){
	min=w;
	s=i;
      }
      else if(min==w){
	if(h[i]<h[s]){
	  s=i;
	}
      }
    }
    for(i=0;i<8;i++){
      if(i!=0)printf(" ");
      printf("%d",m[s+i]);
    }
    printf("\n");
  }
  return 0;
}
