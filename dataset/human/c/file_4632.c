#include<stdio.h>
 
typedef struct T{
    int id;
    int d;
    int h;

     struct T *p;
    struct T *c[2];
  
}t;
 
t tree[100];

int Node(t *n, int d);
 

 
int main(){
    int n, id, id2, i, j;
    t *root = NULL;
    scanf("%d", &n);
    for( i = 0; i < n; i++ ){
        tree[i].id = -1;
        tree[i].p = NULL;
        tree[i].c[0] = NULL;
        tree[i].c[1] = NULL;
        tree[i].d = -1;
        tree[i].h = -1;
    }
    for( i = 0; i < n; i++ ){
        scanf("%d", &id);
        tree[id].id = id;
        scanf("%d", &id2);
        if( 0 <= id2 && id2 < n ){
            tree[id].c[0] = &tree[id2];
            tree[id2].p = &tree[id];
        }
        scanf("%d", &id2);
        if( 0 <= id2 && id2 < n ){
            tree[id].c[1] = &tree[id2];
            tree[id2].p = &tree[id];
        }
    }
    for( i = 0; i < n; i++ ){
        if( tree[i].p == NULL ){
            root = &tree[i];
            break;
        }
    }
    Node(root, 0);
    for( i = 0; i < n; i++ ){

       char *nodetype[3] = {"root", "internal node", "leaf"};
    int pid, sibling = -1, degree = 0, ni;
    if( tree[i].c[0] != NULL ){ degree++; }
    if( tree[i].c[1] != NULL ){ degree++; }
    if( tree[i].p != NULL ){
        if( tree[i].p->c[0] != NULL && tree[i].p->c[0]->id != tree[i].id ){
            sibling = tree[i].p->c[0]->id;
        }else if( tree[i].p->c[1] != NULL && tree[i].p->c[1]->id != tree[i].id ){
            sibling = tree[i].p->c[1]->id;
        }
        if( degree == 0 ){
            ni = 2;
        }else{
            ni = 1;
        }
        pid = tree[i].p->id;
    }else{
        ni = 0;
        pid = -1;
    }
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", 
        tree[i].id, pid, sibling, degree, tree[i].d, tree[i].h, nodetype[ni]
    );

    }
    return 0;
}



int Node(t *n, int d){
    if( n == NULL ){ return -1; }
    n->d = d;
    int lh = Node(n->c[0], d+1);
    int rh = Node(n->c[1], d+1);
    n->h = (lh>rh?lh:rh) + 1;
    return n->h;
}
