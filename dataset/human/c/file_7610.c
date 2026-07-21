#include<stdio.h>
int main(void){
int a[10000],c;
int b=0;
while(1){
scanf("%d",&a[b]);
if(a[b]==0){
break;
}
b++;
}
for(c=1;c<=b;c++){
printf("Case %d: %d\n",c,a[c-1]);
}
return 0;
}
