#include <stdio.h>
int main(){
int sum=0,h=0,i,j,num=0,n,x[10000];
for(i=2;;i++){
for(j=2;j*j<=i;j++){
if(i!=j){if(i%j==0){num=1;}}
}if(num==0){x[h]=i; h++;}num=0;
if(h==10000){break;}
}
while(1){
scanf("%d",&n);
if(n==0) break;
for(i=0;i<n;i++){
	sum+=x[i];
}
printf("%d\n",sum);
sum=0;
}
return 0;
}
