#include<stdio.h>

int box(int boll,int box_capa){
  return boll/box_capa;
}

int main (void){
  int r,g,b,n,n_r,n_rg,i,j,counter = 0;
  scanf("%d %d %d %d",&r,&g,&b,&n);
  for(i = 0 ;i <= box(n,r);i++){
    n_r = n - (r * i);
    for(j = 0 ;j <= box(n_r,g);j++){
      n_rg = n_r - (g * j);
      if(n_rg % b == 0){
        counter ++;
      }
    }
  }  
  printf("%d\n",counter);
  return 0; 
}
