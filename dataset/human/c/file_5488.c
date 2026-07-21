#include<stdio.h>
#include<math.h>
int main(){
int i,j,k;
int sum,n,r,s[10000];
s[0]=2;
for(i=3,j=1;j<10000;i+=2){
r=(int)sqrt(i)+1;
for(k=3;k<r;k+=2){
if(i%k==0)
r=0;
}
if(r){
s[j]=i;
j++;
}
}
for(;;){
scanf("%d",&n);
if(n==0)
break;
sum=0;
for(i=0;i<n;i++)
sum+=s[i];
printf("%d\n",sum);
}
return 0;
}
