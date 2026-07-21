/*
 * FileName:     binary_trees
 * CreatedDate:  2020-04-22 15:03:01 +0900
 * LastModified: 2020-04-22 16:23:53 +0900
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node{
    int number;
    struct _node *pare;
    struct _node *left;
    struct _node *right;
}node;
int max(int s, int t){
    if(s<t){return t;}
    return s;
}
int where_am_i(node* Node){
    if(Node->pare->left==Node){
        return 0;
    }
    else if(Node->pare->right==Node){
        return 1;
    }
}
int sibling_search(node *Node){
    if(Node->pare->left==Node && Node->pare->right!=NULL){
        return Node->pare->right->number;
    }
    else if(Node->pare->left==Node && Node->pare->right==NULL){
        return -1;
    }
    else if(Node->pare->right==Node && Node->pare->left!=NULL){
        return Node->pare->left->number;
    }
    else{
        return -1;
    }
}
int count_child(node* Node){
    if(Node->left!=NULL&&Node->right!=NULL){
        return 2;
    }
    else if(Node->left==NULL&&Node->right!=NULL){
        return 1;
    }
    else if(Node->left!=NULL&&Node->right==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
node *big_pare(node *Node){
    while(Node->pare!=NULL){
        Node = Node->pare;
    }
    return Node;
}
int depth_search(node *Node){
    int count=0;
    while(Node->pare!=NULL){
        count++;
        Node=Node->pare;
    }
    return count;
    
}
int height_search(node *Node){
    if(Node->left!=NULL&&Node->right==NULL){
        return height_search(Node->left)+1;
    }
    else if(Node->left==NULL&&Node->right!=NULL){
        return height_search(Node->right)+1;
    }
    else if(Node->left!=NULL&&Node->right!=NULL){
        int Lc = height_search(Node->left);
        int Rc = height_search(Node->right);
        return max(Lc,Rc)+1;
    }
    else{
        return 0;
    }
    
}
int type_search(node* Node){
    if(Node->pare==NULL){
        return 0;
    }
    else if(Node->left!=NULL || Node->right!=NULL){
        return 1;
    }
    else if(Node->left==NULL && Node->right==NULL){
        return 2;
    }
}
int main(void){
    int n;
    scanf("%d",&n);
    node* Node = (node*)malloc(n*sizeof(node));
    for(int i=0;i<n;i++){
        Node[i].number = i;
    }

    for(int i=0;i<n;i++){
        int id,left,right;
        scanf("%d %d %d",&id,&left,&right);
        if(left==-1){
            Node[id].left=NULL;
        }
        if(right==-1){
            Node[id].right=NULL;
        }
        if(left!=-1){
            Node[id].left = Node+left;
            Node[left].pare = Node+id;
        }
        if(right!=-1){
            Node[id].right = Node+right;
            Node[right].pare = Node+id;
        }
    }
    for(int i=0;i<n;i++){
        printf("node %d: parent = ",i);
        if(Node[i].pare==NULL){
            printf("-1, sibling = -1, ");
        }
        else{
            printf("%d, sibling = %d, ",Node[i].pare->number,sibling_search(Node+i));
        }
        printf("degree = %d, ",count_child(Node+i));
        printf("depth = %d, ",depth_search(Node+i));
        printf("height = %d, ",height_search(Node+i));
        if(type_search(Node+i)==0){
            printf("root\n");
        }
        else if(type_search(Node+i)==1){
            printf("internal node\n");
        }
        else{
            printf("leaf\n");
        }
    }
    free(Node);
    return 0;
}
