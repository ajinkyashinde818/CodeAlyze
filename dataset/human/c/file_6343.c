#include<stdio.h>


int MAX(int a,int  b){


return (((a) > (b)) ? (a) : (b));
}
int MIN(int a,int  b){
      return  (((a) < (b)) ? (a) : (b));
     }
int main(){
  int n;
  int i;
  int R[200000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
  int maxv = -2000000000;
  int minv = R[0];
  for(i=1;i<n;i++){
maxv=MAX(maxv,R[i]-minv);
minv=MIN(minv,R[i]);


  }
  printf("%d\n",maxv);
  return 0;
}
