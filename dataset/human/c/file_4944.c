#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 26
#define NIL (-1)
typedef struct {
    int parent;
    int left;
    int right;
}re;
re T[N];
int n;
int getsibling(int t){
    if(T[t].parent == NIL) return -1;
    else{
        if(T[T[t].parent].left == t) return T[T[t].parent].right;
        else return T[T[t].parent].left;
    }
}
int getdegree(int t){
    int res = 0;
    if(T[t].left != NIL) res++;
    if(T[t].right != NIL) res++;
    return res;
}
int depth(int t){
    if(T[t].parent == NIL) return 0;
    else return depth(T[t].parent) + 1;
}
int height(int t){
    int c1 = 0;
    int c2 = 0;
    if(T[t].left != NIL) c1 = height(T[t].left) + 1;
    if(T[t].right != NIL) c2 = height(T[t].right) + 1;
    return c1 > c2 ? c1 : c2;
}
char * type(int t){
//    char * res = (char *)malloc(30 * sizeof(char));
    char *res;
    if(T[t].parent == NIL) res = "root";
    else{
        if(T[t].left == NIL && T[t].right == NIL) res = "leaf";
        else res = "internal node";
    }
    return res;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) T[i].parent = T[i].left = T[i].right = NIL;

    for(int i = 0; i < n; i++){
        int parent, left, right;
        scanf("%d %d %d", &parent, &left, &right);
        T[parent].left = left;
        T[parent].right = right;
        T[left].parent = parent;
        T[right].parent = parent;
    }

    for(int i = 0; i < n; i++){
        printf("node %d: parent = %d, "
               "sibling = %d, degree = %d, "
               "depth = %d, height = %d, %s\n", i, T[i].parent,
               getsibling(i), getdegree(i),
               depth(i), height(i), type(i)
        );
    }
    return 0;
}
