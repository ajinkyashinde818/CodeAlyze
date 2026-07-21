#include <stdio.h>
#include <stdlib.h>

#define UND_NODE -1
#define UND_HEIGHT -1

typedef struct {
//    int id;
    int right;
    int left;
    int parent;
    int height;
} BinaryNode;

int nodeDepthFromId(BinaryNode nodes[], int length, int id) {
    int i = 0;
    while (nodes[id].parent != UND_NODE) {
        i++;
        id = nodes[id].parent;
    }
    return i;
}

int nodeSiblingFromId(BinaryNode nodes[], int length, int id) {
    if (nodes[id].parent == UND_NODE)
        return UND_NODE;
    
    BinaryNode parentNode = nodes[nodes[id].parent];
    
    if (parentNode.left == id && parentNode.right != UND_NODE)
        return parentNode.right;
    
    if (parentNode.right == id && parentNode.left != UND_NODE)
        return parentNode.left;
    
    return UND_NODE;
}

void constructHeights(BinaryNode nodes[], int length) {
    int i, parentId, heightCount;
    
    for (i = 0; i < length; i++) {
        if (nodes[i].left == UND_NODE && nodes[i].right == UND_NODE) {
            nodes[i].height = 0;

            parentId = nodes[i].parent;
            heightCount = 1;
            while (1) {
                if (parentId == UND_NODE) break;
                if (nodes[parentId].height < heightCount)
                    nodes[parentId].height = heightCount;

                heightCount++;
                parentId = nodes[parentId].parent;
            }
        }
    }
}

void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        if (i) printf(", ");
        printf("%d", array[i]);
    }
}


int main(int argc, char** argv) {
    int nNodes;
    scanf("%d", &nNodes);
    
    BinaryNode nodes[nNodes]; // Binary tree
    int i, j, nodeId, left, right;
    
    for (i = 0; i < nNodes; i++) {
        nodes[i].parent = nodes[i].left = nodes[i].right = UND_NODE;
        nodes[i].height = UND_HEIGHT;
    }
    
    for (i = 0; i < nNodes; i++) {
        scanf("%d", &(nodeId)); // id
        scanf("%d", &(left)); // 
        scanf("%d", &(right)); // 

        nodes[nodeId].left = left;
        nodes[nodeId].right = right;
        nodes[left].parent = nodes[right].parent = nodeId;
    }
    
    // for height
    constructHeights(nodes, nNodes);
    
    int deg = 0;
    
    for (i = 0; i < nNodes; i++) {
        
        // degree
        deg = 0;
        if (nodes[i].left != UND_NODE) deg++;
        if (nodes[i].right != UND_NODE) deg++;
        
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", 
                i, 
                nodes[i].parent, 
                nodeSiblingFromId(nodes, nNodes, i), 
                deg,
                nodeDepthFromId(nodes, nNodes, i),
                nodes[i].height
            );
        
        
        // node types
        if (nodes[i].parent == UND_NODE)
            printf("root");
        else if (nodes[i].height == 0)
            printf("leaf");
        else 
            printf("internal node");
        
        printf("\n");
    }
    

    return (EXIT_SUCCESS);
}
