#include<stdio.h>
#include<string.h>

typedef struct{
    int n,r,l,d,p,dep,h,sub,deg;
}Tree;

Tree tree[30];
int i,j,N,r,l,n;

int dfs(int,int);

int main(){
    memset(tree,-1,sizeof(tree));
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d%d%d",&n,&l,&r);
        tree[n].l=l;
        tree[n].r=r;
        tree[n].deg=(r!=-1)+(l!=-1);
        tree[l].sub=r;
        tree[r].sub=l;
        if(l!=-1) tree[l].p=n;
        if(r!=-1) tree[r].p=n;
    }
    for(i=0;i<N;i++) if(tree[i].p==-1) dfs(i,0);

    for(i=0;i<N;i++) printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",i,tree[i].p,tree[i].sub,tree[i].deg,tree[i].dep,tree[i].h,tree[i].p==-1?"root":tree[i].l==-1&&tree[i].r==-1?"leaf":"internal node");
    return 0;
}

int dfs(int p,int d){
    int a,b;
    if(p==-1) return -1;
    tree[p].dep=d;
    a=dfs(tree[p].r,d+1);
    b=dfs(tree[p].l,d+1);
    if(a==-1&&b==-1) tree[p].h=0;
    else tree[p].h=(a>b?a:b)+1;
    return tree[p].h;
}
