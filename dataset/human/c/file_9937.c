#include <stdio.h>
 
#define max 100000
#define nil -1
void print(int);
void depth(int, int);
 
struct Node {
        int p, l, r;
};
struct Node a[max];
int n,dp[max];
 
int main(){
        int i,j,v,dg,c,l,r;
        scanf("%d",&n);
 
 
        for(i=0; i<n; i++) {
                a[i].p = nil;
                a[i].l = nil;
                a[i].r = nil;
        }
 
        for(i=0; i<n; i++) {
                scanf("%d%d",&v, &dg);
                for(j=0; j<dg; j++) {
                        scanf("%d", &c);
                        if(j==0) {
                                a[v].l = c;
                        }else {
                                a[l].r = c;
                        }
                        l = c;
                        a[c].p = v;
                }
        }
 
        for(i=0; i<n; i++) {
                if(a[i].p == nil) {
                        r = i;
                }
        }
        depth(r, 0);
 
        for(i=0; i<n; i++) {
                print(i);
        }
 
        return 0;
}
 
 
void print(int node) {
        int i, c;
 
        printf("node %d: ",node);
        printf("parent = %d, ", a[node].p);
        printf("depth = %d, ", dp[node]);
 
        if(a[node].p == nil) {
                printf("root, ");
        }else if(a[node].l == nil) {
                printf("leaf, ");
        }else {
                printf("internal node, ");
        }
 
        printf("[");
        c = a[node].l;
        while(c!=nil) {
                if(c==a[node].l) {
                        printf("%d",c);
                }else {
                        printf(", %d", c);
                }
                c = a[c].r;
        }
        printf("]\n");
}
 
 
void depth(int node, int dep){
        dp[node] = dep;
        if(a[node].r!=nil) {
                depth(a[node].r, dep);
        }
        if(a[node].l!=nil) {
                depth(a[node].l, dep+1);
        }
}
