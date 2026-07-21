#include <stdio.h>

#define MAX 100000
#define NIL -1
void Print(int);
void Depth(int, int);

struct Node {
        int p, l, r;
};
struct Node A[MAX];
int n,Dp[MAX];

int main(){
        int i,j,v,deg,c,l,r;
        scanf("%d",&n);


        for(i=0; i<n; i++) {
                A[i].p = NIL;
                A[i].l = NIL;
                A[i].r = NIL;
        }

        for(i=0; i<n; i++) {
                scanf("%d%d",&v, &deg);
                for(j=0; j<deg; j++) {
                        scanf("%d", &c);
                        if(j==0) {
                                A[v].l = c;
                        }else {
                                A[l].r = c;
                        }
                        l = c;
                        A[c].p = v;
                }
        }

        for(i=0; i<n; i++) {
                if(A[i].p == NIL) {
                        r = i;
                }
        }
        Depth(r, 0);

        for(i=0; i<n; i++) {
                Print(i);
        }

        return 0;
}


void Print(int node) {
        int i, c;

        printf("node %d: ",node);
        printf("parent = %d, ", A[node].p);
        printf("depth = %d, ", Dp[node]);

        if(A[node].p == NIL) {
                printf("root, ");
        }else if(A[node].l == NIL) {
                printf("leaf, ");
        }else {
                printf("internal node, ");
        }

        printf("[");
        c = A[node].l;
        while(c!=NIL) {
                if(c==A[node].l) {
                        printf("%d",c);
                }else {
                        printf(", %d", c);
                }
                c = A[c].r;
        }
        printf("]\n");
}


void Depth(int node, int dep){
        Dp[node] = dep;
        if(A[node].r!=NIL) {
                Depth(A[node].r, dep);
        }
        if(A[node].l!=NIL) {
                Depth(A[node].l, dep+1);
        }
}
