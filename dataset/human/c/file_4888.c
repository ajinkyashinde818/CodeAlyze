#include <stdio.h>
#define MAX 10000
#define NILL -1

struct Node{
    int parent,lef,rig;
};

struct Node tree[MAX];
int n,dep[MAX],hi[MAX];

void setDep(int,int);
int setHei(int);
int getSi(int);
void print(int);

int main(){
    int val,le,ro,root = 0,i;
    scanf("%d",&n);
    
    for(i=0;i<n;i++) tree[i].parent = NILL;
    
    for(i=0;i<n;i++){
        scanf("%d %d %d",&val,&le,&ro);
        tree[val].lef = le;
        tree[val].rig = ro;
        if( le != NILL) tree[le].parent = val;
        if( ro != NILL) tree[ro].parent = val;
    }
    
    for(i=0;i<n;i++) if(tree[i].parent == NILL) root = i;
    
    setDep(root,0);
    setHei(root);
    
    for(i=0;i<n;i++) print(i);
    
    return 0;
}


void setDep(int u,int d){
    if( u == NILL) return;
    dep[u] = d;
    setDep(tree[u].lef,d+1);
    setDep(tree[u].rig,d+1);
}

int setHei(int u){
    int h = 0,hh = 0;
    if(tree[u].lef != NILL)
        h = setHei(tree[u].lef) + 1;
    if(tree[u].rig != NILL)
        hh = setHei(tree[u].rig) + 1;
    return hi[u] = (h > hh ? h : hh);
}

int getSi(int u){
    if(tree[u].parent == NILL) return NILL;
    if(tree[tree[u].parent].lef != u && tree[tree[u].parent].lef != NILL)
        return tree[tree[u].parent].lef;
    if(tree[tree[u].parent].rig != u && tree[tree[u].parent].rig != NILL)
        return tree[tree[u].parent].rig;
    return NILL;
}

void print(int u){
    printf("node %d: ",u);
    printf("parent = %d, ",tree[u].parent);
    printf("sibling = %d, ",getSi(u));
    int deg =0;
    if(tree[u].lef != NILL) deg++;
    if(tree[u].rig != NILL) deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",dep[u]);
    printf("height = %d, ",hi[u]);
    
    if(tree[u].parent == NILL){
        printf("root\n");
    }else if( tree[u].lef == NILL && tree[u].rig == NILL){
        printf("leaf\n");
    }else {
        printf("internal node\n");
    }
}
