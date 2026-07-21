#include <stdio.h>
#define MAX 100005
#define NIL -1
struct Node {
    int p;
    int left;
    int right;
};

struct Node Tree[MAX];
int N,D[MAX];

void findDepth(int,int);

int main(){
    int i,j;
    int d,v,c;
    int left,right,value;
    scanf("%d", &N);
    for (i = 0; i < N; i ++) Tree[i].p = Tree[i].right = Tree[i].left = NIL;

    for (i = 0 ; i < N ; i ++) {
        scanf("%d %d",&v, &d);
        for ( j = 0; j < d; j++ ) {
            scanf("%d", &c);
            if (j == 0 ) Tree[v].left = c;
            else Tree[left].right = c;
            left = c;
            Tree[c].p = v;
        }
    }
    for (i = 0 ; i < N ; i ++ ){
        if (Tree[i].p == NIL ) right = i;
    }
    findDepth(right, 0);
    
    for (value = 0; value < N; value ++) {
        printf("node %d: parent = %d, depth = %d, ", value,Tree[value].p,D[value]);

        if ( Tree[value].p == NIL ) printf("root, ");
        else if (Tree[value].left == NIL ) printf("leaf, ");
        else printf("internal node, ");

        printf("[") ;

        for ( i = 0 , c = Tree[value].left; c != NIL ; c = Tree[c].right, i ++ ) {
            if (i) printf(", ");
            printf("%d",c);
        }
        printf("]\n");
    } 
    return 0;
}

void findDepth(int value,int p) {
    if(value == NIL)return;
    D[value] = p;
    findDepth(Tree[value].right, p);
    findDepth(Tree[value].left, p+1);
}
