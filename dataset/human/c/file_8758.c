#include <stdio.h>

int main(){
int N,a[100001],i,b,c,count=0;
scanf("%d",&N);
for(i=0;i<N;i++){
scanf("%d",&a[i]);
}
b=0;
while(a[b]!=2){
if(a[b]==0){
count=-2;
break;
}
c=b;
b=a[b]-1;
a[c]=0;
count++;
}
printf("%d",count+1);
return 0;
}
