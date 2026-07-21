#include<stdio.h>
int main(void){
  char *s="python3 -c\""
"n,m,*a=open(0).read().split();n,m=int(n),int(m);r=range(n-m+1);print('YNeos'[all(a[n:]!=[t[j:j+m]for t in a[i:i+m]]for i in r for j in r)::2])\n"
"\"";
  system(s);
  return 0;
}
