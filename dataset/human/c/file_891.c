#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long

ll n;
int furui[1000000]={};
int sosu[1000000];

int main(){
  scanf("%lld",&n);
  ll ind=2;
  int ind2 =0;
  int flag=1;
  //make sosu map
  while(ind<1000000){
    while(ind<1000000 && furui[ind]==1){
      ind++;}
    if(ind>=1000000) break;
    sosu[ind2]=ind;
    ind2++;
    for(int i=1;i*ind<1000000;i++){
      furui[i*ind]=1;}
  }
  /*for(ll i=0;i<ind2;i++){
    printf("%d\n",sosu[i]);}*/
  ll ans=0;
  for(int i=0;i<ind2;i++){
    int count=0;
    while(n%sosu[i]==0){
      n/=sosu[i];
      count++;}
    int njo=1;
    while(count-njo>=0){
      count-=njo;
      njo++;}
    ans += njo-1;
  }
  if(n>1000000){
    ans+=1;}
  printf("%lld\n",ans);
  
  
  return 0;
}
