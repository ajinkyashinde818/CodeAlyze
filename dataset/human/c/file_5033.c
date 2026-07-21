#include<stdio.h> 
#define MAX 100005 
#define NIL -1 
struct Node_struct{int p, s, d, l, r;}; 
typedef struct Node_struct Node; 
Node T[MAX]; 
int D[MAX]; 
int H[MAX];

void print(int u){ 
int i, c; 
printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p, T[u].s, T[u].d, D[u], H[u]); 

if(T[u].p==NIL) printf("root\n"); 
else if(T[u].l==NIL && T[u].r==NIL) printf("leaf\n"); 
else printf("internal node\n"); 

} 

void calcDepth(int u, int p){ 
    if(u==NIL) return;
    D[u] = p; 
    calcDepth(T[u].l, p+1); 
    calcDepth(T[u].r, p+1); 
} 

int calcHeight(int u){
    int h1=0, h2=0;
    if(T[u].l!=NIL) h1=calcHeight(T[u].l)+1;
    if(T[u].r!=NIL) h2=calcHeight(T[u].r)+1;
    if(h1>h2) return H[u]=h1;
    else return H[u]=h2;
}

int main(){ 
int i, j, k; 
int n; 
int id, child_l, child_r; 
int root = NIL; 
scanf("%d", &n); 
for(i=0; i<n; i++){
    T[i].p = T[i].l = T[i].r = T[i].s = NIL; 
    T[i].d=0;
}

for(i=0; i<n; i++){ 
    scanf("%d%d%d", &id, &child_l, &child_r);
    if(child_l!=NIL){
        T[id].d++;
        T[id].l=child_l;
        T[child_l].p=id;
    }
    if(child_r!=NIL){
        T[id].d++;
        T[child_r].p=id;
        T[id].r=child_r;
    }

    T[child_l].s=child_r;
    T[child_r].s=child_l;
} 

//(find the root) 
for(i=0; i<n; i++){ 
if(T[i].p == -1) root = i; 
} 

//(find depth of each node) 
calcDepth(root, 0); 
calcHeight(root);

//(output) 
for(i=0; i<n; i++) print(i); 

return 0; 
}
