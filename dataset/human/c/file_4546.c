#include<stdio.h>
#define MaxN 26
#define NIL -1

struct node {int parent, left, right;};
node T[MaxN];
int n;

void gets_in()
{
    int id;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        T[i].parent=T[i].left=T[i].right=NIL;
    for(int i=0; i<n; i++){
        scanf("%d", &id);
        scanf("%d %d", &T[id].left, &T[id].right);
        int a=T[id].left, b=T[id].right;
        T[a].parent=id;
        T[b].parent=id;
    }
}

int getDepth(int id)
{
    int res=0;
    int u=id;
    while(T[u].parent!=NIL){
        u=T[u].parent;
        res++;
//        printf("11");
    }
    return res;
}

int getHeight(int id)
{
    int res=0;
    int a=NIL, b=NIL;
    if(T[id].left==NIL && T[id].right==NIL)
        return res;
    if(T[id].left!=NIL)
        a=getHeight(T[id].left)+1;
    if(T[id].right!=NIL)
        b=getHeight(T[id].right)+1;
    res=a>b?a:b;
    return res;

}

void solve()
{
    for(int i=0; i<n; i++){
        printf("node %d: ", i);
        printf("parent = %d, ", T[i].parent);
        if(T[i].parent==NIL)
            printf("sibling = -1, ");
        else{
            int id=T[i].parent;
            if(i==T[id].left)
                printf("sibling = %d, ", T[id].right);
            else if(i==T[id].right)
                printf("sibling = %d, ", T[id].left);
        }
        int num=0;
        if(T[i].left!=NIL) num++;
        if(T[i].right!=NIL) num++;
        printf("degree = %d, ", num);
        printf("depth = %d, ", getDepth(i));
        printf("height = %d, ", getHeight(i));
        if(T[i].parent==NIL)
            printf("root\n");
        else if(T[i].left==NIL && T[i].right==NIL)
            printf("leaf\n");
        else
            printf("internal node\n");
    }
}

int main(void)
{
    gets_in();
    solve();
    return 0;
}
