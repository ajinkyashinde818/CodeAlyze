#include<stdio.h>
int main(){
int a,i;
while(1){
scanf("%d\n",&a);
if(a==0){
break;
}
else{
for(i=0;a!=1;i++){
if(a%2==0){
a=a/2;
}
else{
a=a*3+1;
}
}
}
printf("%d\n",i);
}
return 0;
}
