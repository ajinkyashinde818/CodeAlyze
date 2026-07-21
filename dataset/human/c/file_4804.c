#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int parent;
    int leftChild;
    int rightChild;
    int sibling;
    int degree;
    int depth;
    int height;
} Node;

typedef struct {
    Node *node;
    int num;
} Tree;

typedef enum {
    ROOT,
    INTERNAL_NODE,
    LEAF,
} NodeType;

#define NL -1
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

bool initializeTree(Tree *tree, int num);

void setParent(Tree *tree, int idx, int parent);
void setLeftChild(Tree *tree, int idx, int leftChild);
void setRightChild(Tree *tree, int idx, int rightChild);
void setSibling(Tree *tree, int idx, int sibling);
void setDegree(Tree *tree, int idx, int dgr);
void _setDepth(Tree *tree, int idx, int d);
void setDepth(Tree *tree);
int _setHeight(Tree *tree, int idx);
void setHeight(Tree *tree);

int getRoot(Tree *tree);
int getParent(Tree *tree, int idx);
int getLeftChild(Tree *tree, int idx);
int getRightChild(Tree *tree, int idx);
int getSibling(Tree *tree, int idx);
int getDegree(Tree *tree, int idx);
int getDepth(Tree *tree, int idx);
int getHeight(Tree *tree, int idx);
NodeType getNodeType(Tree *tree, int idx);

char *NodeTypeToString(NodeType type);
void printTree(Tree *tree);
void terminateTree(Tree *tree);

bool initializeTree(Tree *tree, int num) {
    if((tree->node = malloc(num * sizeof(Node))) == NULL) {
        return false;
    }

    for(int i = 0; i < num; i++) {
        Node *ptr = &tree->node[i];
        ptr->parent = ptr->leftChild = ptr->rightChild = ptr->sibling = ptr->depth = ptr->degree = ptr->height = NL;
    }

    tree->num = num;
    return true;
}

void setParent(Tree *tree, int idx, int parent) {
    tree->node[idx].parent = parent;
}

void setLeftChild(Tree *tree, int idx, int leftChild) {
    tree->node[idx].leftChild = leftChild;
}

void setRightChild(Tree *tree, int idx, int rightChild) {
    tree->node[idx].rightChild = rightChild;
}

void setSibling(Tree *tree, int idx, int sibling) {
    tree->node[idx].sibling = sibling;
}

void setDegree(Tree *tree, int idx, int dgr) {
    tree->node[idx].degree = dgr;
}

void _setDepth(Tree *tree, int idx, int d) {
    tree->node[idx].depth = d;

    int leftChild = getLeftChild(tree, idx);
    if(leftChild != NL) {
        _setDepth(tree, leftChild, d + 1);
    } 
    
    int rightChild = getRightChild(tree, idx);
    if(rightChild != NL) {
        _setDepth(tree, rightChild, d + 1);
    }
}

void setDepth(Tree *tree) {
    _setDepth(tree, getRoot(tree), 0);
}

int _setHeight(Tree *tree, int idx) {    
    int h1, h2;
    h1 = h2 = 0;

    int leftChild = getLeftChild(tree, idx);
    if(leftChild != NL) {
        h1 = _setHeight(tree, leftChild) + 1;
    }

    int rightChild = getRightChild(tree, idx);
    if(rightChild != NL) {
        h2 = _setHeight(tree, rightChild) + 1;
    }

    return tree->node[idx].height = MAX(h1, h2);
}

void setHeight(Tree *tree) {
    _setHeight(tree, getRoot(tree));
}

int getRoot(Tree *tree) {
    for(int i = 0; i < tree->num; i++) {
        if(tree->node[i].parent == NL) {
            return i;
        }
    }

    return NL;
}

int getParent(Tree *tree, int idx) {
    return tree->node[idx].parent;
}

int getLeftChild(Tree *tree, int idx) {
    return tree->node[idx].leftChild;
}

int getRightChild(Tree *tree, int idx) {
    return tree->node[idx].rightChild;
}

int getSibling(Tree *tree, int idx) {
    return tree->node[idx].sibling;
}

int getDepth(Tree *tree, int idx) {
    return tree->node[idx].depth;
}

int getHeight(Tree *tree, int idx) {
    return tree->node[idx].height;
}

int getDegree(Tree *tree, int idx) {
    return tree->node[idx].degree;
}

NodeType getNodeType(Tree *tree, int idx) {
    if(getParent(tree, idx) == NL) {
        return ROOT;
    } else if(getDegree(tree, idx) == 0) {
        return LEAF;
    } else {
        return INTERNAL_NODE;
    }
}

char *NodeTypeToString(NodeType type) {
    switch(type) {
        case ROOT         : return "root";
        case LEAF         : return "leaf";
        case INTERNAL_NODE: return "internal node";
        default           : return NULL;
    }
}

void printTree(Tree *tree) {
    for(int i = 0; i < tree->num; i++) {
        printf("node %d: ", i);
        printf("parent = %d, ", getParent(tree, i));
        printf("sibling = %d, ", getSibling(tree, i));
        printf("degree = %d, ", getDegree(tree, i));
        printf("depth = %d, ", getDepth(tree, i));
        printf("height = %d, ", getHeight(tree, i));
        printf("%s\n", NodeTypeToString(getNodeType(tree, i)));
    }
}

void terminateTree(Tree *tree) {
    free(tree->node);
    tree->node = NULL;
    tree->num = 0;
}

int main(void) {
    Tree tree;
    int n;

    scanf("%d", &n);

    initializeTree(&tree, n);

    for(int i = 0; i < n; i++) {
        int parent, left, right;
        scanf("%d %d %d", &parent, &left, &right);

        setLeftChild(&tree, parent, left);
        setRightChild(&tree, parent, right);
        if(left != NL) {
            setParent(&tree, left, parent);
            setSibling(&tree, left, right);
        } if(right != NL) {
            setParent(&tree, right, parent);
            setSibling(&tree, right, left);
        }
        setDegree(&tree, parent, (left != NL) + (right != NL));
    }

    setDepth(&tree);
    setHeight(&tree);

    printTree(&tree);

    terminateTree(&tree);
    return 0;
}
