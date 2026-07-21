#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ABC167D
//ABC167C
int main(void) {
  int n, m, x, k, i, p, cou=0, tmp, min=1e9, price=0;
  scanf(" %d %d %d", &n, &m, &x);
  int c[n], a[n][m], unst[m];
  for(i=0; i<n; i++){
    scanf(" %d", &c[i]);
    for(k=0; k<m; k++)
      scanf(" %d", &a[i][k]);
  }

  for(i=1; i<pow(2, n); i++){
    tmp=i;
    price=0;
    for(k=0; k<m; k++)
      unst[k]=0;

    for(p=0; p<n; p++){
      if(tmp%2==1){
        price+=c[p];
        for(k=0; k<m; k++)
          unst[k]+=a[p][k];
      }
      tmp/=2;
    }
    for(k=0; k<m; k++){
      if(unst[k]>=x){
        if(k==m-1&&min>price) min=price;
      }else break;
    }
  }
  //for(i=0; i<n; i++)
    //printf("c[%d]=%d\n", i, c[i]);
  if(min==1e9)printf("-1");
  else printf("%d", min);
}
