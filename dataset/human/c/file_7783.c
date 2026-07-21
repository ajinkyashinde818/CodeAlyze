#include<stdio.h>
int main(){
int a,b,c,i;
scanf("%d\n",&a);
for(i=0;i<a;i++){
scanf("%d %d\n",&b,&c);
if(b%c==0){
printf("%d\n",c);
}
else{
printf("%d\n",b%c);
}
}
return 0;
}
