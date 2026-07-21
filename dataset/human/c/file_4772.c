#include <stdio.h>
#define MAX 25
int parent[MAX],left[MAX],right[MAX];
int depth(int);
int height(int);
int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)  parent[i] = -1;
    for(int i=0; i<n; i++){
        int id, l, r;
        scanf("%d%d%d",&id,&l,&r);
        left[id] = l;
        if(l != -1) parent[l] = id;
        right[id] = r;
        if(r != -1) parent[r] = id;
    }
    for(int i=0; i<n; i++){
        int sibling,degree=0;
        sibling =(left[parent[i]] == i ? right[parent[i]] : left[parent[i]]);
        if(parent[i] == -1) sibling = -1;
        if(left[i] != -1) degree++;
        if(right[i] != -1) degree++;
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i, parent[i], sibling, degree, depth(i), height(i));
        if(parent[i] == -1) printf("root\n");
        else if(degree == 0) printf("leaf\n");
        else printf("internal node\n");
    }
}
int depth(int node){
    return (parent[node] == -1 ?  0 : depth(parent[node]) + 1);
} 
int height(int n){
    return ((left[n] == -1 ? -1 : height(left[n]) )< (right[n] == -1 ? -1 : height(right[n]) )?(right[n] == -1 ? -1 : height(right[n]) ): (left[n] == -1 ? -1 : height(left[n]) )) + 1;
}
