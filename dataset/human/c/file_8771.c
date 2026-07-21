#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long
#define mod 1000000007

ll n,k;
ll a[212345];
char z;

int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}

int main(){
  scanf("%lld%lld",&n,&k);

  
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);}
  
  
  sortup(a,n);
  
  ll right=n-1,left=0;
  ll count=k;
  ll ans=1;
  if(a[right]>=0 || k%2==0){
    //printf("right\n");
  while(count>0){
    if(count>=2){
      if(a[right]*a[right-1]>a[left]*a[left+1] ){
	ans = ans*a[right]%mod*a[right-1]%mod;
	right-=2;}
      else{
	ans = a[left]*a[left+1]%mod*ans%mod;
	left+=2;}
      count-=2;}
    else{
      ans = (ans*a[right]+mod)%mod;
      right--;
      count--;}
  }
  }
  else{
    //printf("left\n");
    while(count>0){
      if(count>=2){
	ans = a[right]*a[right-1]%mod*ans%mod;
	right-=2;
	count-=2;}
      else{
	ans*=a[right];
	right--;
	ans=(ans+mod)%mod;
	count--;}
    }}
  ans = (ans+mod)%mod;
    
  printf("%lld\n",ans);
  
  return 0;
}
