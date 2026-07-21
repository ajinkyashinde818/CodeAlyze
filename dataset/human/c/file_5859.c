#include<stdio.h>
#define MAX 200000
int max(int,int);
int min(int,int);

int main(){
  int n,i,R[MAX];
  int maxt,mint;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&R[i]);

  maxt=-2000000000;
  mint=R[0];

  for(i=1;i<n;i++){
    maxt = max(maxt,R[i]-mint);
    mint = min(mint,R[i]);
  }

  printf("%d\n",maxt);

  return 0;
}

int max(int a,int b){
  if(a>b){
    return a;
  }else{return b;}
}

int min(int a,int b){
  if(a<b){
    return a;
  }else{return b;}
}
