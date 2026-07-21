#include<stdio.h>

int main(){
int r,g,b,n,cnt=0;
scanf("%d %d %d %d",&r,&g,&b,&n);
for(int i=n/r;i>=0;i--){
for(int j=(n-i*r)/g;j>=0;j--){
if((n-i*r-j*g)%b==0)cnt++;
}
}
printf("%d",cnt);
return 0;
}
