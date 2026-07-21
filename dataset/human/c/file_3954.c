#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
int a,b,k,count;
int count2=0;
scanf("%d %d %d",&a,&b,&k);
for(count=100;;count--){
    if(a%count==0&&b%count==0){count2++;}
    if(count2==k){printf("%d",count);return 0;}
}

}
