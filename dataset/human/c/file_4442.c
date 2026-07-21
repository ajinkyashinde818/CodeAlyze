#include<stdio.h>
int main(void){
  int i,n,flag=0,flag_max=0;
  int a[1001],b[1001];
  
  for(n=0;n<1001;n++){
    a[n]=0;
    b[n]=0;
  }
  scanf("%d",&i);
  for(n=0;n<i;n++) scanf("%d %d",&a[n],&b[n]);
  
  for(n=0;n<i;n++){
    if(a[n]==b[n]) flag++;
    else flag = 0;
    if(flag> flag_max) flag_max = flag;
  }
  if(flag_max>=3) printf("Yes");
  else printf("No");
    
 return 0; 
}
