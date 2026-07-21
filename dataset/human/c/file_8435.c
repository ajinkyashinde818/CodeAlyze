#include<stdio.h>
int main(){
  int i,j,n,m,a[101],st;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=1;i<=m;i++){
    for(j=0;j<n-1;j++){
      if(a[j]%i > a[j+1]%i){
	st=a[j];
	a[j]=a[j+1];
	a[j+1]=st;
      }
    }
  }
    for(i=0;i<n;i++){
      printf("%d\n",a[i]);
    }
    return 0;
  
}
