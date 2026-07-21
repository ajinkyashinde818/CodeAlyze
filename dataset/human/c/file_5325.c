#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
 int n,m,x;
 scanf("%d%d%d",&n,&m,&x);
  
 int a[n][m],c[n];
 int b,d;
 for(b=0;b<n;b++){
  scanf("%d",&c[b]);
  for(d=0;d<m;d++)
   scanf("%d",&a[b][d]);
 }
 
 int bit,cnt[m],money=0,ok,ans=1200001;
 for(bit=1;bit<(1<<n);bit++){
  ok=0;
  for(b=0;b<m;b++)
   cnt[b]=0;
  money=0;
  for(b=0;b<n;b++){
   if(bit&(1<<b)){
    for(d=0;d<m;d++)
     cnt[d]+=a[b][d];
    money+=c[b];
  //  printf("%d %d %d %d\n",bit,b,money,c[b]);
    }} 
   for(b=0;b<m;b++)
    if(cnt[b]<x){
      ok=1;
      break;}
   if(ok==0&&ans>money){
    ans=money;}
   }
 if(ans==1200001){
  puts("-1");return 0;}
 else
  printf("%d\n",ans);
  
return 0;}
