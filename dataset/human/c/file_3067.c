#include<stdio.h>
int main(){
    int a[210000],i,n,j,k;
	
	scanf("%d%d", &k,&n);
	for(i=0; i<n;i++){
		scanf("%d", &a[i]);
	}
  
  j=a[0]+k-a[n-1];
  for(i=0;i<n-1;i++){
    if(a[i+1]-a[i]>=j){
      j=a[i+1]-a[i];
    }

  }
	    printf("%d\n",k-j);
    return 0;
	
}
