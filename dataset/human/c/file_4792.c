//
// Created by kota_ on 2019/12/28.
//
#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (x > y ? x : y)

typedef struct node{
    int id;
    struct node *child_left;
    struct node *child_right;
    struct node *parent;
}Node;

typedef Node* Nodepointer;


Node make_1node(int id){
    Node ret;
    ret.id = id;
    ret.child_left = NULL;
    ret.child_right = NULL;
    ret.parent = NULL;
    return ret;
}

int get_parent_value(Nodepointer);
int get_degree(Nodepointer);
int get_sibling_value(Nodepointer);
int get_depth(Nodepointer);
int get_height(Nodepointer);

int main(){
    int i, j, n, id, depth;
    Nodepointer nodes, parent;
    scanf("%d", &n);
    nodes = malloc(sizeof(Node) * n);
    for(i = 0; i < n; i++){
        // nodeを全部初期化
        nodes[i] = make_1node(i);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &id);
        parent = &nodes[id];
        for(j = 0; j < 2; j++){
            scanf("%d", &id);
            if(id == -1){
                continue;
            }
            if(j == 0){
                parent->child_left = &nodes[id];
            }
            else{
                parent->child_right = &nodes[id];
            }
            nodes[id].parent = parent;
        }

    }
    for(i = 0; i < n; i++){
        parent = &nodes[i];
        printf("node %d: parent = %d, sibling = %d, ",
                i, get_parent_value(parent), get_sibling_value(parent));
        printf("degree = %d, ", get_degree(parent));
        depth = get_depth(parent);
        printf("depth = %d, ", depth);
        printf("height = %d, ", get_height(parent));
        if(depth == 0){
            printf("root");
        }
        else if(parent->child_left != NULL || parent->child_right != NULL){
            printf("internal node");
        }
        else{
            printf("leaf");
        }
        printf("\n");

    }
    free(nodes);
    return 0;
}


int get_parent_value(Nodepointer target) {
    if (target->parent == NULL) {
        return -1;
    } else {
        return target->parent->id;
    }
}

int get_sibling_value(Nodepointer target){
    int ret, i;
    Nodepointer tmp;
    if(target->parent == NULL){
        return -1;
    }
    for(i = 0; i < 2; i++){
        tmp = target->parent;
        if(i == 0){
            tmp = tmp->child_right;
        }
        else{
            tmp = tmp->child_left;
        }
        if(tmp != NULL && tmp->id != target->id){
            return tmp->id;
        }
    }
    return -1;
}

int get_degree(Nodepointer target){
    return (target->child_right != NULL) + (target->child_left != NULL);
}

int get_depth(Nodepointer target){
    int depth = 0;
    while(target->parent != NULL){
        depth++;
        target = target->parent;
    }
    return depth;
}

int get_height(Nodepointer target){
    int ret1, ret2;
    ret1 = ret2 = 0;
    if(target->child_left != NULL){
        ret1 = get_height(target->child_left) + 1;
    }
    if(target->child_right != NULL){
        ret2 = get_height(target->child_right) + 1;
    }
    return max(ret1, ret2);
}
