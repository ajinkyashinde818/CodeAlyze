#define NIL -1
#define MAX 100005
#include <stdio.h>
struct Node {
    int parent;
    int left;
    int right;
};
struct Node T[MAX];

int getDepth(int n) {
    int d = 0;
    while (T[n].parent != NIL) {
        n = T[n].parent;
        d++;
    }
    return d;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    //初始化
    for (int i = 0; i < n; i++) {
        T[i].parent = T[i].left = T[i].right = NIL;
    }
    //构造树，左子右兄
    for (int i = 0; i < n; i++) {
        //v为结点编号 d为子节点数量 l用于内层循环中记录上一个子节点编号
        int v = 0, d = 0, l = 0;
        scanf("%d %d", &v, &d);
        for (int j = 0; j < d; j++) {
            //子节点编号
            int c = 0;
            scanf("%d", &c);
            if (j == 0) {
                T[v].left = c;
            }
            else {
                T[l].right = c;
            }
            //这个技巧要熟练
            l = c;
            T[c].parent = v;
        }
    }
    //输出各结点信息
    for (int i = 0; i < n; i++) {
        printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, getDepth(i));
        if (T[i].parent == NIL) {
            printf("root");
        }
        else if (T[i].left == NIL) {
            printf("leaf");
        }
        else {
            printf("internal node");
        }
        printf(", [");
        int tmp = T[i].left;
        while (tmp != NIL) {
            if (tmp != T[i].left) {
                printf(", ");
            }
            printf("%d", tmp);
            tmp = T[tmp].right;
        }
        printf("]\n");
    }
    return 0;
}
