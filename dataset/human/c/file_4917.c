#include <stdio.h>
#define N 25

typedef struct node{
    int id, depth, height, degree, sibling;
    struct node* parent;
    struct node* left;
    struct node* right;
} NODE;

void calcDepth(NODE* node){
    if(node == NULL) return;
    if(node->parent == NULL) node->depth = 0;
    else node->depth = node->parent->depth+1;
    calcDepth(node->left);
    calcDepth(node->right);
}

void calcHeight(NODE* node){
    if(node == NULL) return;
    calcHeight(node->left);
    calcHeight(node->right);

    if((node->left == NULL) && (node->right == NULL)) node->height = 0;
    else if((node->left != NULL) && (node->right == NULL)){
        node->height = node->left->height+1;
    }
    else if((node-> left == NULL) && (node->right != NULL)){
        node->height = node->right->height+1;
    }
    else if((node->left->height) > (node->right->height)){
        node->height = node->left->height+1;
    }
    else node->height = node->right->height+1;
}

int main(){
    int i, j, n;
    int id, leftid, rightid, root;
    NODE node[N];

    scanf("%d",&n);

    for(i = 0; i < n; i++){
        node[i].parent = NULL;
        node[i].degree = 0;
        node[i].left = NULL;
        node[i].right = NULL;
    }

//nodeへの情報入力
    for(i = 0; i < n; i++){
        scanf("%d",&id);
        node[id].id = id;

        scanf("%d",&leftid);
        if(leftid != -1){
            node[id].degree++;
            node[leftid].id = leftid;
            node[id].left = &node[leftid];
            node[leftid].parent = &node[id];
        }

        scanf("%d",&rightid);
        if(rightid != -1){
            node[id].degree++;
            node[rightid].id = rightid;
            node[id].right = &node[rightid];
            node[rightid].parent = &node[id]; 
        }   

//siblingについて
        if((leftid != -1) && (rightid == -1)){
            node[leftid].sibling = -1;
        }
        else if((leftid == -1) && (rightid != -1)){
            node[rightid].sibling = -1;
        }
        else if((leftid != -1) && (rightid != -1)){
            node[leftid].sibling = rightid;
            node[rightid].sibling = leftid;
        }
    }

//depthについて
    i = 0;
    while(1){
        if(node[i].parent == NULL){
            root = i;
            break;
        }
        i++;
    }

    calcDepth(&node[root]);
    calcHeight(&node[root]);

//出力
    for(i = 0; i < n; i++){
        printf("node %d: ",i);

        printf("parent = ");
        if(node[i].parent == NULL) printf("-1, ");
        else printf("%d, ",node[i].parent->id);

        printf("sibling = ");
        if(node[i].parent == NULL) printf("-1, ");
        else printf("%d, ",node[i].sibling);

        printf("degree = %d, ",node[i].degree);

        printf("depth = %d, ",node[i].depth);

        printf("height = %d, ",node[i].height);

        if(node[i].parent == NULL) printf("root");
        else if((node[i].left == NULL) && (node[i].right == NULL)) printf("leaf");
        else printf("internal node");

        printf("\n");
    }


return 0;
}
