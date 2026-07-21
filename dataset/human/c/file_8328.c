#include<stdio.h>
int n, k, i;
char s[11], c;
int main(void){
  scanf("%d%s%d", &n, s, &k);
  c=s[k-1];
  for(i=0; i<n; i++){
    if(s[i]==c){
      putchar(c);
    }else{
      putchar('*');
    }
  }
  puts("");
}
