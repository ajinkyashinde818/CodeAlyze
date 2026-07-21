#include<stdio.h>
int main(){
  int n,m,k,i;
  scanf("%d %d %d",&n,&m,&k);
  int** A[n][m+1];
  for(i=0;i<n;i++){
    int j,x;
     for(j=0;j<m+1;j++){
       scanf("%d",&x);
       A[i][j]=x;
     }
  }
  int p,P,sum=-1;
  P=(int)pow(2,n);
  for(p=0;p<P;p++){
    int q,r=p,s;
    int N[m+1];
    for(s=0;s<m+1;s++){
      N[s]=0;
    }
    for(q=0;q<n;q++){
      if(r%2==1){
        for(s=0;s<m+1;s++){
          int vd,vf;
          vd=N[s];
          vf=A[q][s];
          N[s]=vd+vf;
        }
      }
      r=r/2;
    }
    for(s=1;s<m+1;s++){
      if(N[s]<k){
        break;
      }
      if(s==m){
        if(sum==-1){
          sum=N[0];
        }else if(sum>N[0]){
          sum=N[0];
        }
      }
    }
  }
  printf("%d",sum);
  return 0;
}
