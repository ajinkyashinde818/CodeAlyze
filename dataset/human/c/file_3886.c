#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  long a[3];
  long n=0;
  int i,j,h;
    for(i=0;i<3;i++){
    scanf("%ld",a+i);
  }
if(a[0]<a[1]){
  h=a[0];
}else{
  h=a[1];
}

for(i=h;i>0;i--){
  if(a[0]%i==0){
    if(a[1]%i==0){
      n++;
      if(n==a[2]){
        break;
      }
    }
  }
}

  printf("%d",i);



//   long b[a[1]];
//   long c[a[1]];
//   long d[a[1]];//番目
//   long *e;
//   e = (long *)malloc(sizeof(long) * a[0]*a[1]);
//   long *f;
//   f = (long *)malloc(sizeof(long) * a[0]*a[1]);
//   for(i=0;i<a[0]*a[1];i++){
//     e[i]=0;
//     f[i]=0;
//   }
//   long g[a[0]];
//     for(i=0;i<a[0];i++){
//     g[i]=0;
//   }
//   for(j=0;j<a[1];j++){
//     scanf("%ld",b+j);
//     scanf("%ld",c+j);
//     e[(b[j]-1)*a[1]+g[b[j]-1]]=c[j];
//     f[(b[j]-1)*a[1]+g[b[j]-1]]=j;
//     d[j]=1;
//     g[b[j]-1]++;
//     for(h=0;h<g[b[j]-1];h++){
//       if(e[(b[j]-1)*a[1]+h]==0){}
//       else if(e[(b[j]-1)*a[1]+h]<c[j]){
//         d[j]++;
//       }
//       else if(e[(b[j]-1)*a[1]+h]>c[j]){
//         d[f[(b[j]-1)*a[1]+h]]++;
//       }
//     }
//   }
// for(i=0;i<a[1];i++){
//   printf("%06d",b[i]);
//   printf("%06d\n",d[i]);
// }
// for(i=0;i<a[1]*a[0];i++){
//   printf("%d,",e[i]);
// }
}
