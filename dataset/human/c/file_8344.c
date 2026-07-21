#include <stdio.h>
int main() {
  int n,k;
  char s[n];
  scanf("%d%s%d",&n,s,&k);
k=k-1;
  for(int i=0;i<n;i++){
    if(s[i]==s[k]){
    printf("%c",s[i]);
    }else{
    printf("*");
    }
  }
  return 0;
}
