#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int id;
    int degree;
    int height;
    Node* parent;
    Node* cbling;
    Node* rchild;
    Node* lchild;
    
};
int findHeight(Node *a);
void initialize(Node* n);
int findDepth(Node* a);
int main(int argc, char** argv) {
    int size;
    scanf("%d", &size);
    Node array[size];
    
    
    for(int i=0;i<size;i++)
    {
        initialize(&array[i]);
    }
    int location1, location2, tempP, tempC = -1;
    for(int i=0;i<size;i++)
    { 
        scanf("%d ", &tempP);
        array[tempP].id = tempP;
        scanf("%d %d",&location1, &location2);
        if(location1!=-1&&location2!=-1)
        {
            array[location1].cbling = array + location2;
            array[location2].cbling = array + location1;
            
        }
        if(location1!=-1)
        {
            array[tempP].lchild = array + location1; 
            array[location1].parent = array + tempP;
            array[tempP].degree++;
        }
        if(location2!=-1)    
        {
            array[tempP].rchild = array + location2;
            array[location2].parent = array + tempP;
            array[tempP].degree++;
        }
        
    }
    
    int temp, temp2P, type, tempCbling;
    for(int i=0; i<size; i++)
    {
        printf("node %d: ", i);
        if(array[i].parent == NULL)
            temp2P = -1;
        else
            temp2P = array[i].parent->id;
        printf("parent = %d, ", temp2P);
        if(array[i].cbling == NULL)
            tempCbling = -1;
        else
            tempCbling = array[i].cbling->id;
        printf("sibling = %d, ", tempCbling);
        printf("degree = %d, ", array[i].degree);
        printf("depth = %d, ", findDepth(&array[i]));
        printf("height = %d, ", findHeight(&array[i]));
        if(array[i].parent==NULL)
            type = 1;
        else{
            if(array[i].lchild!=NULL || array[i].rchild!=NULL)
                type = 2;
            else
                type = 3;
        }
        if(type == 1)
        {
            printf("root");
        }
        if(type == 2)
        {
            printf("internal node");
        }
        if(type == 3)
        {
            printf("leaf");
        }
      
        printf("\n");
        
    }
    
    return (EXIT_SUCCESS);
}


void initialize(Node* n)
{
    n->id = -1;
    n->degree = 0;
    n->height = -1; 
   n->rchild = NULL;
    n->lchild = NULL;
    n->cbling = NULL;
    n->parent = NULL;
}

int findDepth(Node* a)
{
    int count = 0;
    if(a->parent !=NULL)
    {
        count++;
        count = count + findDepth(a->parent);  
    }
    return count;
}

int findHeight(Node *a)
{
    int count;
    
    int count1 = 0;
    if(a->lchild !=NULL)
    { 
        count1++;
        if(a->height != -1)
            count1 = count1 + a->lchild->height;
        else
            count1 = count1 + findHeight(a->lchild);  
    }
    
    int count2 = 0;
    if(a->rchild !=NULL)
    {
        count2++;
        if(a->rchild->height != -1)
            count2 = count2 + a->rchild->height;
        else
            count2 = count2 + findHeight(a->rchild);  
    }
    if(count1>count2)
        count = count1;
    else 
        count = count2;
    
    return count;
}
