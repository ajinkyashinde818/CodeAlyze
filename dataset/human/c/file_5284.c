#include <stdio.h>
#define NIL -1
int P[10000],L[10000],R[10000],B[10000];
int getDegree(int x){
    int a=0;
    if(L[x]!=NIL)a++;
    if(R[x]!=NIL)a++;
    return a;
}
int getDepth(int y){
    int b=0;
    while(P[y]!=NIL){
        y=P[y];
        b++;
    }
    return b;
}
int getHeight(int z){
    int c=0;
    int d=0;
    if(R[z]!=NIL){
        c=getHeight(R[z])+1;
    }
    if(L[z]!=NIL){
        d=getHeight(L[z])+1;
    }
    if(c>d)return c;
    else return d;
}
int main()
{
    int i,n,s,l,r;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        P[i]=NIL;
        L[i]=NIL;
        R[i]=NIL;
        B[i]=NIL;
    }
for(i=0;i<n;i++){
    scanf("%d%d%d",&s,&l,&r);
    L[s]=l;
    R[s]=r;
    if(l!=NIL)P[l]=s;
    if(r!=NIL)P[r]=s;
    B[l]=r;
    B[r]=l;
}
for(i=0;i<n;i++){
printf("node %d: ",i);
printf("parent = %d, ",P[i]);
printf("sibling = %d, ",B[i]);
printf("degree = %d, ",getDegree(i));
printf("depth = %d, ",getDepth(i));
printf("height = %d, ",getHeight(i));
if(P[i]==NIL)printf("root\n");
else if (L[i]==NIL&&R[i]==NIL)printf("leaf\n");
else printf("internal node\n");
}
    return 0;
}
