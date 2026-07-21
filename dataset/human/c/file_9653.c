#include<stdio.h>
#define NIL -1

struct Node{
    int parent; //節点の親
    int left;   //節点の一番左の子
    int right;  //節点のすぐ右の兄弟
};

Node T[100000];
int D[100000];

void print(int u){
    printf("node %d: parent = %d, depth = %d, ", u, T[u].parent, D[u]);

    if(T[u].parent==NIL) printf("root, ");
    else if(T[u].left==NIL) printf("leaf, ");
    else printf("internal node, ");

    printf("[");
    for(int i=0, c=T[u].left; c!=NIL; i++, c=T[c].right){
        if(i) printf(", ");
        printf("%d", c);
    }
    printf("]\n");
}

//再帰的に深さを求めていく
int rec(int u, int d){  //節点uの深さはd
    D[u] = d;
    //再起する順番が大事
    if(T[u].right!=NIL) rec(T[u].right, d);
    if(T[u].left!=NIL) rec(T[u].left, d+1);
}


int main(){

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    for(int i=0; i<n; i++){
        int v, d;
        scanf("%d %d", &v, &d);
        for(int j=0; j<d; j++){
            int c,l;
            scanf("%d", &c);
            if(j==0)T[v].left = c;
            else T[l].right = c;
            l=c;
            T[c].parent=v;
        }
    }
    int r;
    for(int i=0; i<n; i++){
        if(T[i].parent==NIL) r = i;
    }

    rec(r, 0);

    for(int i=0; i<n; i++) print(i);

    return 0;

}
