#include<stdio.h>

int main(){
  
  int n;
  int A[200000];
  int i,j,max=-999999999;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=n-1;i>=0;i--){

    if(A[i]<max)continue;
    
    for(j=i-1;j>=0;j--){
      if(A[i]-A[j]>max) max = A[i]-A[j];
    }
  }
  printf("%d\n",max);


  
  return 0;
}
