#include<stdio.h>
int main(void){
  char a[4];
  int i,b=0,c=0;
  scanf("%s",a);
  for(i=0;i<4;i++){
    if(a[i]=='a') b++;
    if(a[i]=='b') c=c+2;
    if(a[i]=='c') b=b+3;
  }
  if(b==4&&c==2) printf("Yes\n");
  else printf("No\n");
  return 0;
}
