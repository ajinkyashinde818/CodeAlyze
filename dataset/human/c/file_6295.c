#include<stdio.h>
#include<limits.h>
int main(void){

  int n;
  n=0;
  scanf("%d",&n);
  int a[n];
  for(int k=0;k<n;k++){
    a[k]=0;
  }
  int i=0;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int l=a[0];
  int m=INT_MIN;

  for(int j=1;j<n;j++){
       if(m<a[j]-l){
      m=a[j]-l;
    }
    if(l>a[j]){
      l=a[j];
    }
   
    
  }
  printf("%d\n",m);
  return 0;
}
