#include<stdio.h>
int main(){
int a,b,c=-1000000000,d,i;
scanf("%d\n",&a);
scanf("%d\n",&b);
d=b;
for(i=1;i<a;i++){
scanf("%d\n",&b);
if(c<b-d){
c=b-d;
}
if(d>b){
d=b;
}
}
printf("%d\n",c);
return 0;
}
