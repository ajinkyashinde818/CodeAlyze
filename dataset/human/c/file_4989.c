#include <stdio.h>
#include <stdlib.h>
#define NIL -1
typedef struct List
{
    int parent;
    int leftchild;
    int rightchild;
}List;
int TreeHeight(int ID, List* Tree)
{
    int leftheight = 0, rightheight = 0;
    if(Tree[ID].leftchild==NIL&&Tree[ID].rightchild==NIL){return 0;}
    if(Tree[ID].leftchild!=NIL){leftheight=TreeHeight(Tree[ID].leftchild,Tree);}
    if(Tree[ID].rightchild!=NIL){rightheight=TreeHeight(Tree[ID].rightchild,Tree);}
    return leftheight >= rightheight? leftheight + 1:rightheight + 1;
}
int CountDepth(List* l, int ID)
{
    int counter=0;
    while(l[ID].parent!=NIL)
    {
        counter++;
        ID = l[ID].parent;
    }
    return counter;
}

int main(int argc, const char * argv[]) {
    int n, nodeID=0;
    scanf("%d", &n);
    List* Tree = (List*)malloc(n*sizeof(List));
    for(int i=0;i<n;i++){Tree[i].parent=NIL;}
    for(int i=0;i<n;i++)
    {
        scanf("%d", &nodeID);
        scanf("%d %d", &Tree[nodeID].leftchild, &Tree[nodeID].rightchild);
        Tree[Tree[nodeID].leftchild].parent=nodeID;
        Tree[Tree[nodeID].rightchild].parent=nodeID;
    }
    for(int i=0;i<n;i++)
    {
        printf("node %d: parent = %d, ", i, Tree[i].parent);
        if(Tree[i].parent == NIL){printf("sibling = -1, ");}
        else if(Tree[Tree[i].parent].rightchild==i)
            {printf("sibling = %d, ", Tree[Tree[i].parent].leftchild);}
        else{printf("sibling = %d, ", Tree[Tree[i].parent].rightchild);}
        if(Tree[i].leftchild==NIL&&Tree[i].rightchild==NIL){printf("degree = 0, ");}
        else if(Tree[i].leftchild!=NIL&&Tree[i].rightchild!=NIL){printf("degree = 2, ");}
        else{printf("degree = 1, ");}
        printf("depth = %d, ", CountDepth(Tree, i));
        printf("height = %d, ", TreeHeight(i, Tree));
        if(Tree[i].parent==NIL){printf("root\n");}
        else if(Tree[i].leftchild==NIL&&Tree[i].rightchild==NIL){printf("leaf\n");}
        else{printf("internal node\n");}
    }
    free(Tree);
    return 0;
}
