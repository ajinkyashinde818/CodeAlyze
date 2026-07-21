#include<stdio.h>
int main(){
int n,d,x,a[100],b,i,ans=0;
scanf("%d %d %d",&n,&d,&x);
for(i=0;i<n;i++){
b=1;
scanf("%d",&a[i]);
do{
ans++;
b+=a[i];
}while(b<=d);
}
ans+=x;
printf("%d",ans);
}
