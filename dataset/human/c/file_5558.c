#include<stdio.h>
#include<math.h>
int main(){
int a[10001],b=2,c=3,d=0,e,i,f=0;
for(i=0;i<10000;){
if(b==2){
a[i]=2;
i++;
}
else if(b%2==0 || b==1){
}
else{
while(c<=sqrt(b)){
if(b%c==0){
d++;
break;
}
c++;
}
if(d==0){
a[i]=b;
i++;
}
d=0;
}
b++,c=3;
}
while(1){
scanf("%d\n",&e);
if(e==0){
break;
}
else{
for(i=0;i<e;i++){
f=f+a[i];
}
printf("%d\n",f);
f=0;
}
}
return 0;
}
