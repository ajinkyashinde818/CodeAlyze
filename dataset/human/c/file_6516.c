#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

  int num,i,*r,maxv,minv;
 
  while(1){

    scanf("%d",&num);
    if(num>=2&&num<=2000000) break;
  }
    r = (int *)malloc(num * sizeof(int));
    for(i=0;i<num;i++){
      scanf("%d",&r[i]);
      if(r[i]<1||r[i]>pow(10,9)) break;
      }
    maxv = r[1]-r[0];
    minv = r[0];
    for(i=1;i<=num-1;i++){
      if(r[i]-minv>maxv)
	maxv = r[i]-minv;
      else
	maxv = maxv;
      
      if(r[i]<minv)
	minv = r[i];
      else
	minv = minv;
    }
    printf("%d\n",maxv);



  return 0;
}
