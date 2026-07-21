#include <stdio.h>
#define MAX 100005
#define NIL -1
struct Node {
    int p; // parent
    int l; // left-child
    int r; // right-sibling
};

struct Node T[MAX];
int n, D[MAX]; //D[i]: save the depth from root to point i 

void setDepth( int u, int p ) {
    D[u] = p;
    if (T[u].r != NIL) setDepth(T[u].r, p);
    if (T[u].l != NIL) setDepth(T[u].l, p+1);
}

int getDepth(int u) {
    int d = 0;
    while (T[u].p != NIL) {
        u = T[u].p;
        d++;
    }
    return d;
}

void printChildren(int u) {
    printf("[") ;
    for ( int i = 0 , c = T[u].l; c != NIL ; c = T[c].r, i ++ ) {
        if (i) printf(", ");
        printf("%d",c);
    }

    printf("]\n");
}

void makeTree() {
    int i, j, d, v, c,l, r, u;
    for (i = 0 ; i < n ; i ++) T[i].p = T[i].r = T[i].l = NIL;

    for (i = 0 ; i < n ; i ++) {
        scanf("%d %d",&v, &d);  // v: parent d: the number of childs
        for ( j = 0 ; j < d ; j++ ) {
            scanf("%d", &c);    //c: child
            if (j == 0 ) T[v].l = c; //most left child for v(parent)
            else T[l].r = c;
            l = c; //set the child number to l
            T[c].p = v; //set the parent number for c(children)
        }
    }

}
int main(void) {
    int i, j, d, v, c,l, r, u;
    scanf("%d", &n);

    makeTree();

    for (i = 0 ; i < n ; i ++ ){
        if (T[i].p == NIL ) r = i; // point i is root because i don't have a parent.
    }
    setDepth(r, 0);
    
    for (u = 0 ; u < n ; u ++) {

        printf("node %d: parent = %d, depth = %d, ", u, T[u].p, getDepth(u));

        if ( T[u].p == NIL ) printf("root, ");
        else if (T[u].l == NIL ) printf("leaf, ");
        else printf("internal node, ");

        printChildren(u);

    } 
    return 0;
}
