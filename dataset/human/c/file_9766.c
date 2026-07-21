#include <stdio.h>

typedef struct Node{
    struct Node* parent;
    struct Node* next;
    struct Node* son;
    unsigned int id;
}Node;

int get_depth(Node* node){
    if(node->parent==NULL)
        return 0;
    else
        return get_depth(node->parent)+1;
}

int main(){
    int Node_num;
    scanf("%d", &Node_num);
    Node node[Node_num];
    Node *nodes[Node_num];
    for(int i=0;i<Node_num;i++){
        nodes[i] = &node[i];
        nodes[i]->next = NULL;
        nodes[i]->parent = NULL;
        nodes[i]->son = NULL;
    }
    for(int i=0;i<Node_num;i++){
        int id;
        int sons;
        scanf("%d %d", &id, &sons);
        nodes[id]->id = id;
        int first_son,next_son;
        if(sons--!=0){
            scanf("%d", &first_son);
            nodes[id]->son = nodes[first_son];
            nodes[first_son]->parent = nodes[id];
            next_son = first_son;
        }
        while(sons-->0){
            int next_son_id;
            scanf("%d", &next_son_id);
            nodes[next_son]->next = nodes[next_son_id];
            nodes[next_son_id]->parent = nodes[id];
            next_son = next_son_id;
        }
    }
    for(int i=0;i<Node_num;i++){
        printf("node %d: parent = ", i);
        if(nodes[i]->parent!=NULL){
            printf("%d,", nodes[i]->parent-nodes[0]);
        }
        else
            printf("-1,");
        printf(" depth = %d, ", get_depth(nodes[i]));
        if(nodes[i]->parent==NULL)
            printf("root,");
        else if(nodes[i]->son==NULL)
            printf("leaf,");
        else
            printf("internal node,");
        printf(" [");
        if(nodes[i]->son!=NULL){
            Node * first_son = nodes[i]->son;
            printf("%d", first_son-nodes[0]);
            while(first_son->next!=NULL){
                printf(", %d", first_son->next-nodes[0]);
                first_son = first_son->next;
            }
        }
        printf("]\n");
    }
}
