#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



void swap (int *x, int *y) {
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;

  return;
}


int gcd(int a, int b){
  int c;

  while (b > 0){
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}

long int modpow(long int a,long int n,long int mod){
  long int ans=1;
  while(n>0){
    if(n & 1){
      ans=ans*a%mod;
    }
    a=a*a%mod;
    n/=2;
  }
  return ans;
}

long int modinv(long int a,long int mod){
  return modpow(a,mod-2,mod);
}

int max(int a,int b){
  if(a<b){
    return b;
  }
  else{
    return a;
  }
}

int min(int a,int b){
  if(a<b){
    return a;
  }
  else{
    return b;
  }
}

void chmax(int *a,int b){
  if(*a < b){
    *a = b;
  }

  return;
}

void chmin(int *a,int b){
  if(*a > b){
    *a =b;
  }

  return;
}

int main(void){
  int r,g,b,n;
  scanf("%d%d%d%d",&r,&g,&b,&n);
  int ans=0;
  for(int i=0;r*i<=n;i++){
    for(int j=0;g*j<=n-r*i;j++){
      if((n-(r*i+g*j))%b==0){
        ans++;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
