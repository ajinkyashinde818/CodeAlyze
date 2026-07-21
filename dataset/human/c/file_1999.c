#include<stdio.h>
int main()
{
int a,b,c,k,m;
scanf("%d %d %d",&a,&b,&c);
if(c==0&&b!=0&&a!=0){
k=b;
}else if(b==0&&c!=0&&a!=0){
if(a<c){
k=a+1;
}else if(a>=c){
k=c;
}
}else if(a==0&&b!=0&&c!=0){
if(b>=c){
k=b+c;
}else if(b<c){
k=2*b+1;
}
}else if(a==0&&b==0&&c!=0){
k=1;
}else if(a==0&&c==0&&b!=0){
k=b;
}else if(b==0&&c==0&&a!=0){
k=0;
}else if(a!=0&&b!=0&&c!=0){
if((a+b)<=c){
m=c-a;
if(m==b){
	k=2*b+a;
}else if(m<b){
	k=b+c;
}else if(m>b){
	k=2*b+a+1;
}
}else{
k=b+c;
}
}
printf("%d\n",k);
}
