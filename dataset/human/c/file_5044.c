#include <stdio.h>

#define NIL -1

typedef struct node {
    int parent, left, right;
}Node;

Node T[26];

int getSibling(int i){
    if (T[i].parent == NIL || T[T[i].parent].left == NIL ||
                                T[T[i].parent].right == NIL)
        return NIL;
    if (T[ T[i].parent ].left == i)
        return T[ T[i].parent ].right;
    else
        return T[ T[i].parent ].left;
}

int getDegree(int i){
    int num = 0;
    if (T[i].left != NIL)
        num++;
    if (T[i].right != NIL)
        num++;
    return num;
}

int getDepth(int i){
    int num = 0;
    while (T[i].parent != NIL){
        num++;
        i = T[i].parent;
    }
    return num;
}

int getHeight(int i){
    int left, right;
    left = right = 0;
    if (T[i].left != NIL)
        left = getHeight(T[i].left) + 1;
    if (T[i].right != NIL)
        right = getHeight(T[i].right) + 1;
    return left > right ? left : right;
}

void print(int n){
    for (int i = 0; i < n; i++){
        printf("node %d: parent = %d, sibling = %d, degree = %d, ",
                        i, T[i].parent, getSibling(i), getDegree(i));
        printf("depth = %d, height = %d, ", getDepth(i), getHeight(i) );
        if (T[i].parent == NIL)
            printf("root\n");
        else if (getDegree(i) != 0)
            printf("internal node\n");
        else
            printf("leaf\n");
    }
}

int main(){
    int n, num, p;
    scanf("%d", &n);
    for (int i = 0 ; i < n; i++){
        T[i].parent = NIL;
        T[i].left = NIL;
        T[i].right = NIL;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        scanf("%d %d", &T[num].left, &T[num].right);
        if (T[num].left != NIL)
            T[T[num].left].parent = num;
        if (T[num].right != NIL)
            T[T[num].right].parent = num;
    }


    print(n);

    return 0;
}
//兄弟节点编号，先找爹，再找和自己不同编号的那个
//度，数非NIL个数
//深度，递归求解?
//高度，从叶往上数?
