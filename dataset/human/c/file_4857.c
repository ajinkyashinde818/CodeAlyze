#include <stdio.h>
#define MAX 10000
#define NIL -1

void setDepth(int, int);
int setHeight(int);
int getSibling(int);
void print(int);

struct Node{
    int p;
    int l;
    int r;
};

struct Node T[MAX];
int D[MAX], H[MAX];

int main(){
    int n, i, id, l, r;
    scanf("%d",&n);

    for(i=0; i<n; i++) T[i].p = NIL;

    for(i=0; i<n; i++){
        scanf("%d%d%d",&id,&l,&r);

        T[id].l = l;
        T[id].r = r;
        if(l != NIL) T[l].p = id;
        if(r != NIL) T[r].p = id;
    }

    r=0;
    for(i=0; i<n; i++){
        if(T[i].p == NIL) r=i;
    }

    setDepth(r, 0);
    setHeight(r);

    for(i=0; i<n; i++)  print(i);

    return 0;
}

void setDepth(int u, int d){
    if(u == NIL)  return;

    D[u] = d;
    setDepth(T[u].r, d+1);
    setDepth(T[u].l, d+1);
}

int setHeight(int u){
    int h1 = 0, h2 = 0;

    if(T[u].l != NIL) h1 = setHeight(T[u].l) + 1;
    if(T[u].r != NIL) h2 = setHeight(T[u].r) + 1;
    if(h1 > h2) H[u] = h1;
    else H[u] = h2;

    return H[u];
}

int getSibling(int u){
    if(T[u].p == NIL) return NIL;
    if(T[T[u].p].l != u && T[T[u].p].l != NIL) return T[T[u].p].l;
    if(T[T[u].p].r != u && T[T[u].p].r != NIL) return T[T[u].p].r;
    return NIL;
}

void print(int u){
    printf("node %d: parent = %d, sibling = %d, ",u,T[u].p,getSibling(u));
    int d=0;
   
    if(T[u].l != NIL) d++;
    if(T[u].r != NIL) d++;

    printf("degree = %d, depth = %d, height = %d, ",d,D[u],H[u]);
   
    if(T[u].p == NIL) printf("root\n");
    else if(d == 0) printf("leaf\n");
    else printf("internal node\n");
}
