#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define NIL -1

typedef struct node {
    int p;
    int l;
    int r;
} Node;

Node no[MAX];
int D[MAX];



int setDepth(int u, int p){
    D[u] = p;
    if(no[u].l != NIL){
        setDepth(no[u].l, p + 1);
    } 
    if (no[u].r != NIL){
        setDepth(no[u].r, p);
    }
}

void print(int u){
    int i, c;
    printf("node ");
    printf("%d: ", u);

    printf("parent = %d, ", no[u].p);
    printf("depth = %d, ",  D[u]);
    if(no[u].p == NIL) printf("root, ");
    else if (no[u].l == NIL ) printf("leaf, ");
    else printf("internal node, ");

    printf("[");
    for(i = 0, c = no[u].l; c != NIL; i++, c = no[c].r){
        if(i) printf(", ");
        printf("%d", c);
    }
    printf("]");

    printf("\n");


}

int main(){
    int n, i, j, v, l = 0;
    int tmp;
    int a[10];

    scanf("%d", &n);
    /* initialize */
    for(i = 0; i < n; i++){
        no[i].p = no[i].l = no[i].r = NIL;
    }

    for(i = 0; i < n; i++){
        int id, k;
        scanf("%d%d", &id, &k);
    
        for(j = 0; j < k; j++){
            int c;
            tmp = scanf("%d", &c);
            if(j == 0) no[id].l = c;
            else no[l].r = c;
            l = c;
            no[c].p = id;
        }
    }

    int r;
    for(i = 0; i < n; i++){
        if(no[i].p == NIL) r = i;
    }
    setDepth(r, 0);
    for(i = 0; i < n; i++) print(i);
    return 0;
}
