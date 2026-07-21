#include<stdio.h>
int main(void){
  char *s="python3 -c\""
"d,g=map(int,input().split())\n"
"l=[list(map(int,input().split()))for _ in range(d)]\n"
"for i in range(d):\n"
"    s=l[i][0]*100*-~i\n"
"    l[i].append(s+l[i][1])\n"
"    l[i].append(s)\n"
"a=10**18\n"
"for i in range(1<<d):\n"
"    s=t=k=0\n"
"    for j in range(d):\n"
"        if (i>>j)&1:\n"
"            s+=l[j][2]\n"
"            t+=l[j][0]\n"
"        else:\n"
"            k=j\n"
"    if s+l[k][3]<g:continue\n"
"    if s<g:\n"
"        t+=-(-(g-s)//(100*-~k))\n"
"    a=min(a,t)\n"
"print(a)\n"
"\"";
  system(s);
  return 0;
}
