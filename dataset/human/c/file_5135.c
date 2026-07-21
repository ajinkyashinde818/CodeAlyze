/* 
 * File:   main.c
 * Author: s1252007
 *
 * Created on July 27, 2018, 11:57 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define NIL -1

typedef struct { int parent, left, right; }Node;

Node Tree[MAX];
int size, Depth[MAX], Height[MAX];

int getDepth(int u);
int getSibling(int u);
void print(int u);

int main(int argc, char** argv) {
    int i, index, left, right;
    scanf("%d", &size);

    for ( i = 0; i < size; i++ ) {
      Tree[i].parent = NIL;
    }

    for ( i = 0; i < size; i++ ){
      scanf("%d %d %d", &index, &left, &right);
      Tree[index].left = left;
      Tree[index].right = right;
      if ( left != NIL ) Tree[left].parent = index;
      if ( right != NIL ) Tree[right].parent = index;
    }

    for ( i = 0; i < size; i++ ){
        Depth[i] = getDepth(i);
        Height[i] = 0;
    }

    for ( i = 0; i < size; i++ )
    {
        if ( Tree[i].left == NIL && Tree[i].right == NIL )
        {
            Height[i] = 0;
            int p = Tree[i].parent;
            int c = 1;
            while(1)
            {
                if ( p == NIL ) break;
                if ( Height[p] < c ) Height[p] = c;
                c++;
                p = Tree[p].parent;
            }
        }
    }

    for ( i = 0; i < size; i++ ) print(i);
    return (EXIT_SUCCESS);
}

int getDepth(int u)
{
    int depth = 0;
    while(1)
    {
        u = Tree[u].parent;
        if ( u == NIL ) break;
        depth++;
    }
    return depth;
}

int getSibling(int u)
{
    if ( Tree[u].parent == NIL ) return NIL;
    if ( Tree[Tree[u].parent].left != u && Tree[Tree[u].parent].left != NIL ) return Tree[Tree[u].parent].left;
    if ( Tree[Tree[u].parent].right != u && Tree[Tree[u].parent].right != NIL ) return Tree[Tree[u].parent].right;
    return NIL;
}

void print(int u){
    printf("node %d: ", u);

    printf("parent = %d, ", Tree[u].parent);
    printf("sibling = %d, ", getSibling(u));
    int degree = 0;
    if ( Tree[u].left != NIL ) degree++;
    if ( Tree[u].right != NIL ) degree++;
    printf("degree = %d, ", degree);
    printf("depth = %d, ", Depth[u]);
    printf("height = %d, ", Height[u]);

    if ( Tree[u].parent == NIL ) printf("root\n");
    else if ( Tree[u].left == NIL && Tree[u].right == NIL ) printf("leaf\n");
    else printf("internal node\n");
}
