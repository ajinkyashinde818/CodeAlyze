#include<stdio.h>
#define MAX 100005
#define NIL -1
 
struct Node{
    int p;
    int l;
    int r;
};
struct Node np[MAX];
int depth = 0;
int hileft = 0;
int hiright = 0;
 
 
int get_depth(int u){
 
    if(np[u].p == NIL) return 0;
    if(np[u].p != NIL){
        depth++;
        get_depth(np[u].p);
    }
    return depth;
}
 
int degree(int u){
    if (np[u].l == NIL && np[u].r == NIL) return 0;
    else if(np[u].l != NIL && np[u].r != NIL)  return 2;
    else  return 1;
}
 
int sibling(int u){
 
    if(np[u].p == NIL) {
        return NIL;
    }
    else if(np[np[u].p].l == u) {
        return np[np[u].p].r;
    }
    else {
        return np[np[u].p].l;
    }
}
 
int hight(int u){
 
    int hileft = 0;
    int hiright = 0;
 
    if(np[u].l != -1) {
        hileft = hight(np[u].l) + 1;
    }
    if(np[u].r != -1){
        hiright = hight(np[u].r) + 1;
    }
    if(hileft < hiright){
        return hiright;
    }
    else {
        return hileft;
    }
}
 
void print(int u){
 
    printf("node %d: ",u);
    printf("parent = %d, ",np[u].p);
    printf("sibling = %d, ",sibling(u));
    printf("degree = %d, ",degree(u));
 
    depth = 0;
 
    printf("depth = %d, ",get_depth(u));
    printf("height = %d, ",hight(u));
 
    if(np[u].p == NIL)printf("root\n");
    else if(np[u].l == NIL && np[u].r == NIL) {
        printf("leaf\n");
    }
    else {
        printf("internal node\n");
    }
}
 
 
int main(){
    int i, j;
    int d, v, c, l;
    int n,tmp;
 
    scanf("%d", &n);
 
    for (i = 0; i < n; i++) {
        np[i].p = np[i].l = np[i].r = NIL;      // 初期化
    }
    for (i = 0; i <n ; i++){
        scanf("%d %d %d", &v, &d, &c);
        np[d].p = np[c].p = v;
        np[v].l = d;
        np[v].r = c;
    }
 
    for (i = 0; i < n; i++ ) {
        print(i);
    }
    return 0;
}
