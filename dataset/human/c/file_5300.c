#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int id;
    struct node *parentNode;
    struct node *firstChild;
    struct node *sibling;
};
 
struct node* createNode(int);
struct node* searchNode(int);
int getHeight(struct node* nd);
 
struct node* nodes[26];
int n;
 
int main(){
 
int i,j;
int id;
int tmpId;
int left, right;
int depth;
struct node* currentNode;
struct node* tmpNode;
struct node* leftChild;
struct node* rightChild;
 
scanf("%d",&n);
     
for(i=0;i<n;i++){
     
    scanf("%d",&id);
    currentNode = createNode(id);
     
    scanf("%d",&left);
    leftChild = createNode(left);
    scanf("%d",&right);
    rightChild = createNode(right);
     
    if(leftChild){
        leftChild->sibling = rightChild;
        leftChild->parentNode = currentNode;
        currentNode->firstChild = leftChild;
    }
    if(rightChild){
        rightChild->sibling = leftChild;
        rightChild->parentNode = currentNode;
        if(leftChild==NULL) currentNode->firstChild = rightChild;
    }
     
}
     
    for(i=0; i<n; i++){
         
        printf("node %d: ",nodes[i]->id);
        printf("parent = %d, ",(nodes[i]->parentNode?nodes[i]->parentNode->id:-1));
        printf("sibling = %d, ",(nodes[i]->sibling?nodes[i]->sibling->id:-1));
        printf("degree = ");
        if(nodes[i]->firstChild){
            if(nodes[i]->firstChild->sibling) printf("2");
            else printf("1");
        }else{
            printf("0");    
        }
        printf(", ");
         
        depth = 0;
        tmpNode = nodes[i]->parentNode;
        while(tmpNode){
            depth++;
            tmpNode = tmpNode->parentNode;
        }
        printf("depth = %d, ",depth);
        printf("height = %d, ",getHeight(nodes[i]));
 
        if(depth==0) printf("root");
        else if(nodes[i]->firstChild==NULL) printf("leaf");
        else printf("internal node");
         
        printf("\n");
         
    }
 
return 0;
}
 
struct node* createNode(int id){
    struct node *newNode;
    if(id < 0) return NULL;
    if(newNode = searchNode(id)) return newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->id=id;
    newNode->parentNode = NULL;
    newNode->firstChild = NULL;
    newNode->sibling = NULL;
    nodes[id] = newNode;
    return newNode;
}
 
struct node* searchNode(int id){
    if(nodes[id]) return nodes[id];
    return NULL;
}
 
int getHeight(struct node* nd){
    int tmpLeft=-1, tmpRight=-1;
    if(nd->firstChild) tmpLeft = getHeight(nd->firstChild);
    if(nd->firstChild && nd->firstChild->sibling) tmpRight = getHeight(nd->firstChild->sibling);
    return (tmpLeft>tmpRight?tmpLeft:tmpRight)+1;
}
