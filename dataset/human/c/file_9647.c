#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int number;       //
    int parent_num;
    int depth;
    char var[20];
    int child_num;    //
    int *children;    //
} Node;

void dfs_set_var_depth(Node array[], int depth, int index){
    
    array[index].depth = depth;
    int cn = array[index].child_num;
    
    if(array[index].parent_num == -1){
        strncpy(array[index].var, "root", sizeof("root") + 1);
    }
    else if(cn == 0){
        strncpy(array[index].var, "leaf", sizeof("leaf") + 1);
    }
    else{
        strncpy(array[index].var, "internal node", sizeof("internal node") + 1);
    }
    
    if(cn == 0) return;
    
    REP(i,cn){
        int child_index = array[index].children[i];
        dfs_set_var_depth(array, depth + 1, child_index);
    }
    
}


int main(int argc, const char * argv[]) {
    //Input
    int n,id,k, c, root_num;
    
    scanf("%d", &n);
    
    Node * node_array = NULL;
    node_array = (Node *)malloc(sizeof(Node) * n);
    
    
    //set value into Node struct
    REP(i,n){
        scanf("%d", &id);
        scanf("%d", &k);
        node_array[id].number = id;
        node_array[id].parent_num = -1;
        node_array[id].depth = 0;
        node_array[id].child_num  = k;
        if(k > 0){
            node_array[id].children = (int *)malloc( sizeof(int) * k );
            REP(j,k){
                scanf("%d", &c);
                node_array[id].children[j] = c;
            }
        }
    }
    
    //set parent_num
    int cn;
    REP(i,n){
        cn = node_array[i].child_num;
        int parent_index = node_array[i].number;
        
        REP(j,cn){
            int child_index = node_array[i].children[j];
            node_array[child_index].parent_num = parent_index;
        }
    }
    
    //choose parent node
    REP(i,n){
        if(node_array[i].parent_num == -1){
            root_num = i;
            break;
        }
    }
    
    //set depth, var
    dfs_set_var_depth(node_array, 0, root_num);
    
    //print answer
    REP(i,n){
        printf("node %d: parent = %d, depth = %d, %s, [", node_array[i].number, node_array[i].parent_num, node_array[i].depth, node_array[i].var);
        
        int cn = node_array[i].child_num;
        REP(j,cn){
            printf("%d", node_array[i].children[j]);
            if(j != cn - 1){
                printf(", ");
            }
        }
        printf("]\n");
    }

    //free memory
    REP(i,n){
        if(node_array[i].child_num > 0){
            free(node_array[i].children);
        }
    }
    free(node_array);
    
    return 0;
}
