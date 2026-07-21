#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long int

ll n,k;
ll a[200002];
ll came[200002]; //check if came before

int main(){

  scanf("%lld%lld",&n,&k);
  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);}

  ll loopmae;
  ll inloop;
  ll tmp=1;
  for(ll i=1;i<=n+1;i++){
    if(came[tmp]!=0){
      loopmae = came[tmp]-1;
      inloop = i-came[tmp];
      break;}
    came[tmp]=i;
    tmp = a[tmp];}

  if(k<=loopmae){
    tmp =1;
    for(int i=0;i<k;i++){
      tmp=a[tmp];}}
  else{
  k-=loopmae;
  k%=inloop;
  for(ll i=0;i<k;i++){
    tmp = a[tmp];}}

  

  printf("%lld\n",tmp);

  
  return 0;
}
