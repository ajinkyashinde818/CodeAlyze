#include<stdio.h>
#include<string.h>

struct record{
 int a;
 int b;
};

int check;

int main(void){
  
  int i,n;
  struct record r[n];
  if(scanf("%d",&n)==1) for(i=0;i<n;i++) {
    if( scanf("%d",&r[i].a)==1 ) ;
    if( scanf("%d",&r[i].b)==1 ) ;
  }
  
  for(i=0;i<n;i++){
    if(r[i].a==r[i].b) check++;
    else check=0;
    if(check >= 3) break;
  }
  
  if(check >= 3) printf("Yes\n");
  else  printf("No\n");
  
  return 0;
}
