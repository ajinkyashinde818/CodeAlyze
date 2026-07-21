#include<stdio.h>
#define N 200000
int bigger(int,int);
int smaller(int,int);

int main(){
  int n,i,j;
  int R[N];
  int maxv,minv;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }

  maxv=R[1]-R[0];
  minv=R[0];

  for(j=1;j<n;j++){
      maxv=bigger(maxv,R[j]-minv);
      minv=smaller(minv,R[j]);
  }

  printf("%d\n",maxv);
  return 0;
}

int bigger(int a,int b){
  if(a>b) return a;
  else return b;
}

int smaller(int a,int b){
  if(a<b) return a;
  else return b;
}
