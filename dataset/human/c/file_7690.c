#include<stdio.h>

int main(void){
   int i=0,n=0;
   int a[10000];
   for(i=0;i<10000;i++){
    scanf("%d",&a[i]);
       if(a[i]==0)
       break;
       
       n++;
   }
   
   for(i=0;i<n;i++)
    printf("Case %d: %d\n",i+1,a[i]);

	return 0;
}
