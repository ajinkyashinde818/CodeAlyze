#include <stdio.h>

int main(){
  
  int n,k,i;
  scanf("%d",&n);
  
  char s[n];
  scanf("%s",&s);
  scanf("%d",&k);
  
  for(i=0;i<n;i++){
    if(s[i]!=s[k-1]){
      s[i] = '*';
    }
  }
  
  puts(s);
  
  return 0;
}
