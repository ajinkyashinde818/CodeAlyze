#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void swap (int *x, int *y) {
  int temp;    

  temp = *x;
  *x = *y;
  *y = temp;
}

int gcd(int a,int b){
  if(a<b){
    swap(&a,&b);
  }

  if(b==0){
    return a;
  }

  int r=a%b;
  while(r!=0){
    a = b;
    b = r;
    r = (a%b);
  }

  return b;
}

/* クイックソート */
int dn(const void*a,const void*b){return*(int*)b-*(int*)a;}


int modpow(int a,int n,int mod){
  int ans=1;
  while(n>0){
    if(n & 1){
      ans=ans*a%mod;
    }
    a=a*a%mod;
    n/=2;
  }
  return ans;
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


/****************************************\
| Thank you for viewing my code:)        |
| Written by RedSpica a.k.a. RanseMirage |
| Twitter:@asakaakasaka                  | 
\****************************************/

int main(void){
  int n,m,x;
  scanf("%d%d%d",&n,&m,&x);

  int C[n];
  int A[n][m];
  for(int i=0;i<n;i++){
    scanf("%d",&C[i]);
    for(int j=0;j<m;j++){
      scanf("%d",&A[i][j]);
    }
  }


  int ans=10000000;
  
  //000000
  //000001
  //000010
  //000011
  //000100
  //000101
  //...
  //111111=2^7-1

  for(int bit=0;bit<(1<<n);bit++){
    int price=0;//今いくら分参考書を買ったか
    int B[m];//どれくらい経験値が貯まったか
    for(int i=0;i<m;i++){
      B[i]=0;
    }

    for(int i=0;i<n;i++){
      if(bit & (1<<i)){//その本を買う
        price+=C[i];//値段を追加
        for(int j=0;j<m;j++){
          B[j]+=A[i][j];
        }
      }
    }

    int can=1;
    for(int i=0;i<m;i++){
      if(B[i]<x){
        can=0;
      }
    }

    if(can==1){
      chmin(&ans,price);
    }
  }

  if(ans!=10000000){
    printf("%d\n",ans);
  }
  else{
    printf("-1\n");
  }

  return 0;
}
