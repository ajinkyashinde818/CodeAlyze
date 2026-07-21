#include<stdio.h>
int main(void){
  char *s="python3 -c\""
"from bisect import*\n"
"A,B=abs,bisect\n"
"a,b,q,*l=map(int,open(0).read().split())\n"
"f=2**60\n"
"s,t=[-f]+l[:a]+[f],[-f]+l[a:a+b]+[f]\n"
"for x in l[a+b:]:\n"
"  m=f\n"
"  i,j=B(s,x),B(t,x)\n"
"  for v in s[i-1:i+1]:\n"
"    for w in t[j-1:j+1]:\n"
"      m=min(m,A(x-v)+A(v-w),A(x-w)+A(w-v))\n"
"  print(m)\n"
"\"";
  system(s);
  return 0;
}
