#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100010
#define NIL (-1)
typedef struct {
    int parent;
    int left;
    int right;
}re;
re T[N];
int n;
int getDepth(re t){
    if(t.parent == NIL){
        return 0;
    }
    else return getDepth(T[t.parent]) + 1;
}

void printChild(re t){
    int firstchild = t.left;
    int res[n];
    int k = 0;
    if(firstchild != NIL){
        res[k++] = firstchild;
        while(T[firstchild].right != NIL){
            res[k++] = T[firstchild].right;
            firstchild = T[firstchild].right;
        }
        printf("[");
        for(int i = 0; i < k; i++){
            if(i == k-1){
                printf("%d]\n", res[i]);
            }
            else printf("%d, ", res[i]);
        }
    }
    else{
        printf("[]\n");
    }
}
int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; i++) T[i].parent = T[i].left = T[i].right = NIL;

    for(int p = 0; p < n; p++){
        int node, time;
        scanf("%d %d", &node, &time);
        int c;
        for(int k = 0; k < time; k++){
            int t;
            scanf("%d", &t);
            if(k == 0){
                T[node].left = t;
            }
            else{
                T[c].right = t;
            }
            c = t;
            T[c].parent = node;
        }
    }

    for(int i = 0; i < n; i++){
        int depth = getDepth(T[i]);
        char s[30];
        if(T[i].parent == NIL){
            strcpy(s, "root");
        }
        else{
            if(T[i].left == NIL){
                strcpy(s, "leaf");
            }
            else{
                strcpy(s, "internal node");
            }
        }

        printf("node %d: parent = %d, depth = %d, %s, ", i, T[i].parent, depth, s);
        printChild(T[i]);
    }
    return 0;
}
