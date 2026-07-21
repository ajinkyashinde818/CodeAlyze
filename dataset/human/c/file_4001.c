#include <stdio.h>
int main(){
int a,b,k,i,e;
scanf("%d%d%d",&a,&b,&k);
int count;
count=0;

for(i=100; i>=1; i--){
if(a%i==0 && b%i==0){count++; e=i;}
if(count==k){printf("%d",e);
return 0;
}
}
}
