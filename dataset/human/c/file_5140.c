#include <stdio.h>

typedef struct{
    int son[2];
    int par;
    int sib;
    int deg;
    int dep;
    int hei;
} Tree;
Tree t[25];

int hei(int u)
{
  int h1 = 0, h2 = 0;

  if(t[u].son[0] != -1) h1 = hei(t[u].son[0])+1;
  if(t[u].son[1] != -1) h2 = hei(t[u].son[1])+1;

  if(h1 >= h2) return t[u].hei = h1;
  if(h2 > h1)return t[u].hei = h2;
}

int main()
{
    int i,n,id,j,max,root;

    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        t[i].par=-1;
        t[i].sib=-1;
        t[i].deg=0;
        t[i].dep=0;
    }
    
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&id);
        scanf("%d%d",&t[id].son[0],&t[id].son[1]);
        if (t[id].son[0]==-1&&t[id].son[1]==-1)
        {
            t[id].deg=0;
        }
        else if (t[id].son[0]!=-1&&t[id].son[1]!=-1)
        {
            t[id].deg=2;
            t[t[id].son[0]].sib=t[id].son[1];
            t[t[id].son[1]].sib=t[id].son[0];
            t[t[id].son[0]].par=id;
            t[t[id].son[1]].par=id;
        }
        else
        {
            t[id].deg=1;
            if(t[id].son[0]!=-1){
            t[t[id].son[0]].sib=t[id].son[1];
            t[t[id].son[0]].par=id;
            }
            else
            {
            t[t[id].son[1]].sib=t[id].son[0];
            t[t[id].son[1]].par=id;
            }
        }
    }

    for ( i = 0; i < n; i++)
    {
        for ( j = t[i].par; j !=-1; j=t[j].par)
        {
            t[i].dep++;
        }
        if (t[i].dep==-1) root=i;
        hei(i);
    }


    for ( i = 0; i < n; i++)
    {
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, " ,i,t[i].par,t[i].sib,t[i].deg,t[i].dep,t[i].hei);
        if (t[i].deg==0)
        {
            if (t[i].dep==0)
            {
                printf("root\n");
            }
            else
            printf("leaf\n");
        }
        else
        {
            if (t[i].dep==0)
            {
                printf("root\n");
            }
            else
            {
                printf("internal node\n");
            }

        }
    }
   return 0;
}
