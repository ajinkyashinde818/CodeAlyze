#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SENT 1000000000


typedef struct NODE{
    int node_num;
    int parent;
    int sibling;
    int child_num;
    int child_left;
    int child_right;
    int depth;
    int height;
    char var[20];
}NODE;


void setParent(NODE*A, int N){
    
    int i;
    
    for(i=0; i< N; i++){
        if(A[i].child_left != -1) A[A[i].child_left].parent = i;
        if(A[i].child_right != -1) A[A[i].child_right].parent = i;
    }
    
}

int getRoot(NODE * A, int N){
    int i;
    int ans = -1;
    
    for (i=0; i < N; i++) {
        if (A[i].parent == -1) {
            ans = i;
            break;
        }
    }
    return ans;
}

void setDepth(NODE *A, int N, int root, int height){
    
    if (root < 0 || root >= N) {
        return;
    }
    A[root].depth = height;

    setDepth(A, N, A[root].child_left, height + 1);
    setDepth(A, N, A[root].child_right, height + 1);
    
}

void setHeight_sub(NODE *A, int N, int node_num, int height){
    
    if (node_num < 0 || node_num >= N){
        return;
    }
    
    if(A[node_num].height  < height){
        A[node_num].height = height;
    }
    
    setHeight_sub(A, N, A[node_num].parent, height+1);
    
}

void setHeight(NODE *A, int N){
    int i;
    for (i= 0; i < N; i++) {
        if(A[i].child_left == -1 && A[i].child_right == -1){
            setHeight_sub(A, N, i, 0);
        }
    }
}



void setVariation(NODE * A, int N, int root){
    
    int i;
    
    for (i=0; i < N; i++) {
        
        if (A[i].parent == -1) {
            strcpy(A[i].var, "root");
            continue;
        }
        
        if (A[i].child_right != -1 || A[i].child_left != -1) {
            strcpy(A[i].var, "internal node");
            continue;
        }
        
        strcpy(A[i].var, "leaf");
        
    }
}

void setSibling(NODE * A, int N){
    int i, left, right;
    
    for (i=0; i < N; i++) {
        left = A[i].child_left;
        right = A[i].child_right;
        
        if (left != -1 ){
            A[left].sibling  = right;
        }
        
        if ( right != -1 ){
            A[right].sibling = left;
        }
        
    }
    
}


void setChildNum(NODE * A, int N){
    
    int i;
    for (i=0; i < N; i++) {
        
        if (A[i].child_right != -1 && A[i].child_left != -1) {
            A[i].child_num = 2;
        }
        else if (A[i].child_right != -1 || A[i].child_left != -1){
            A[i].child_num = 1;
        }
        else{
            A[i].child_num = 0;
        }
    }
    
}


int main(){
    
    int i,n, node_num, root;
    NODE * A;
    
    //the number
    scanf("%d",&n);
    
    A = (NODE*)malloc(sizeof(NODE)*n);
    
    for (i=0; i<n; i++) {
        scanf("%d", &node_num);
        A[node_num].node_num = node_num;
        scanf("%d %d", &(A[node_num].child_left), &(A[node_num].child_right));
        A[node_num].parent = -1;
        A[node_num].depth = -1;
        A[node_num].height = -1;
        A[node_num].sibling = -1;
        strcpy(A[node_num].var, "root");
    }
    
    setParent(A, n);
    root = getRoot(A, n);
    
    setChildNum(A,n);
    setSibling(A, n);
    setDepth(A, n, root, 0);
    setHeight(A, n);
    setVariation(A, n, root);

    
    for (i=0; i<n; i++) {
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", A[i].node_num, A[i].parent, A[i].sibling, A[i].child_num, A[i].depth, A[i].height, A[i].var);
    }
    
    free(A);
    
    return 0;
}
