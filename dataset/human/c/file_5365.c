#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


int main(){

 long long int N,M,X;
  scanf("%lld %lld %lld",&N,&M,&X);

/*
  char A[];
  scanf("%s",A);
  */

  
  long long int A[M+1];
  long long int mon;
  mon =0;
  long long int ans;
  ans = 0;
  long long int i,j,k,l;
  for(i=1;i<=M;i++){
    A[i]=0;
  }
  long long int B[N+1][M+1];
  long long int C[N+1];
  int cou;
  cou = 0;

  for(i=1;i<=N;i++){

   scanf("%lld",&C[i]);
   for(j=1;j<=M;j++){
   scanf("%lld",&B[i][j]);
   }
   }
  k = pow(2,N);
  for(i=0;i<k;i++){
   for(j=0;j<N;j++){
     if(i>>j & 1){
       mon += C[j+1];
       for(l=1;l<=M;l++){
         A[l]+=B[j+1][l];
       }
       }
   }
       for(l=1;l<=M;l++){
         if(A[l]<X){
           cou = 1;
         }
       }
       if ( cou == 0){
         if(ans==0){
           ans = mon;
         }
         else if(mon<ans){
           ans = mon;
         }
        else{}
       }
       cou = 0;
       mon = 0;
  for(l=1;l<=M;l++){
    A[l]=0;
  }
  }
if(ans != 0){
           printf("%lld",ans);
}
else{
  printf("-1");
}




 /* long long int a,b,c;
  a=B[1][1];
  b=1;
for(i=2;i<=N;i++){
  if(a<=B[i][1]){
    a=B[i][1];
    b=i;
  }
}
  mon += C[b];
  c = B[b][1];
  for(i=1;i<=M;i++){
    A[i] += B[b][i];
    if(
  
for(i=1;i<=N;i++){
  for(j=1;j<=M;j++){
    A[j]+=B[i][j];
    Ac[j]=A[j];
  }
  mon += C[i];
}

for(i=1;i<=M;i++){
  if(A[i]<X){
    printf("-1");
    return(0);
  }
}
long long int check;
long long int monc,monmoto;
monc = mon;
monmoto = mon;
for(i=1;i<=N;i++){
  monc = monmoto;
  for(l=i;l<=N;l++){
 check =0;

 for (j=1;j<=M;j++){
   if(Ac[j]-B[l][j]>=X){
     new[j]=Ac[j]-B[l][j];
   }
   else{
     check =1;
   }
 }
 if (check == 0){
   for (k=1;k<=M;k++){
     Ac[k]=new[k];
   }
     monc = monc - C[l];
 }


  }


  for(l=1;l<=M;l++){
    Ac[l]=A[l];
  }
  if(monc<=mon){
mon = monc;
}
}
printf("%lld",mon);
*/






 return(0);
 }
