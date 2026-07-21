#include<stdio.h>
#include<string.h>

int main(){
  int H,W,count=0;
  char cs[55][55]={"."};
  scanf("%d %d",&H,&W);
  for(int l=0;l<H;l++){	scanf("%s",cs[l]);}
  for(int l=0;l<H;l++){
    for(int l2=0;l2<W;l2++){
      if(cs[l][l2]=='#' && cs[l-1][l2]!='#' && cs[l+1][l2]!='#' && cs[l][l2-1]!='#' && cs[l][l2+1]!='#'){
        count++;
      }
    }
  }
  if(count==0){printf("Yes");}else{printf("No");}
  return 0;
}
