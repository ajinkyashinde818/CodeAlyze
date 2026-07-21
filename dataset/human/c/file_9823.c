#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
 
#define MAX 100005
#define NIL -1
 
typedef struct node{int p,l,r;}Node;
Node T[MAX];
int D[MAX];
 
void print(int u )
{
    int i,c;
    printf("node %d: parent = %d, depth = %d, ",u,T[u].p,D[u]);
    if(T[u].p==NIL)printf("root, ");
    else if(T[u].l==NIL)printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    for(i=0,c=T[u].l;c!=NIL;c=T[c].r,i++)
    {
        if(i)printf(", ");
        printf("%d",c);
    }
    printf("]\n");
}
 
void rec(int u,int p)
{
    D[u]=p;
    if(T[u].l != NIL)rec(T[u].l,p+1);
    if(T[u].r != NIL)rec(T[u].r,p);
}
 
int main()
{
    int n,l,root,i, v,d,c,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)T[i].p=T[i].l=T[i].r=NIL;
 
    for( i=0;i<n;i++)
    {
        scanf("%d%d",&v,&d);
        for(j=0;j<d;j++)
        {
            scanf("%d",&c);
            if(j==0)T[v].l=c;
            else T[l].r=c;
            l=c;
            T[c].p=v;
        }
    }
    for( i=0;i<n;i++)
    {
        if(T[i].p==NIL)root=i;
    }
    rec(root,0);
    for( i=0;i<n;i++)print(i);
}
