#include <stdio.h>
int main(void){
    
int a,b,k,i,j=0;
int x,y;
int s[100];

scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&k);


    
    for(i=100; i>=1; i--){
        if(b%i==0 && a%i==0){
        s[j]=i;
        j++;

        }
    }

printf("%d\n",s[k-1]);
}
