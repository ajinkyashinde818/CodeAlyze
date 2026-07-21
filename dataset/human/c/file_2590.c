#include <stdio.h>

int main(void){
  char a[4];
  int ans=0;
  scanf("%s\n",a);
for (int i = 0; i < 3; i++) {
  if (a[i]=='a') {
    ans+=1;
  }
  if (a[i]=='b') {
    ans+=2;
  }
  if (a[i]=='c') {
    ans+=4;
  }
}
if (ans==7) {
  printf("Yes\n");
}else{
  printf("No\n");
}
  return 0;
}
