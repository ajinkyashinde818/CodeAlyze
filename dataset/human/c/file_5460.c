#include<stdio.h>
#include<stdlib.h>
int main(){
int v,w,x,y,min=1000000000,k,h,n,i,ans=0,a,e,f,g;
scanf("%d %d %d\n",&k,&h,&n);
scanf("%d %d\n",&e,&f);
for(i=1;i<n;i++){
v=e,w=f;
scanf("%d %d\n",&x,&y);
e=x,f=y,g=v,h=w;
a=abs(v-x)+abs(y-w);
if(a<min){
min=a;
}
if(v>x){
a=v-x;
w=w-a;
a=a+abs(w-y);
}
else{
a=x-v;
w=w+a;
a=a+abs(w-y);
}
if(a<min){
min=a;
}
x=e,y=f,v=g,w=h;
if(w>y){
a=w-y;
v=v-a;
a=a+abs(v-x);
}
else{
a=y-w;
v=v+a;
a=a+abs(v-x);
}
if(a<min){
min=a;
}
ans=ans+min;
min=1000000000;
}
printf("%d\n",ans);
return 0;
}
