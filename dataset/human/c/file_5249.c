#include <stdio.h>

int parent[25];
int left[25];
int right[25];

int degree(int node){
    int d = 0;
    if(left[node] != -1) d++;
    if(right[node] != -1) d++;
    return d;
}

int depth(int node){
    if(parent[node] == -1)
        return 0;
    else
        return depth(parent[node]) + 1;
}

int height(int node){
    int l = left[node];
    int r = right[node];
    int hl = l == -1 ? -1 : height(l);
    int hr = r == -1 ? -1 : height(r);
    return (hl < hr ? hr : hl) + 1;
}

int sibling(int node){
    int p = parent[node];
    if(p == -1)
        return -1;
    if(left[p] == node)
        return right[p];
    else
        return left[p];
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        parent[i] = -1;
    for(int i=0; i<n; i++){
        int id, l, r;
        scanf("%d%d%d", &id, &l, &r);
        left[id] = l;
        right[id] = r;
        if(l != -1) parent[l] = id;
        if(r != -1) parent[r] = id;
    }
    for(int i=0; i<n; i++){
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, "
               "height = %d, ",
               i, parent[i], sibling(i), degree(i), depth(i), height(i));
        if(parent[i] == -1)
            printf("root\n");
        else if(degree(i) == 0)
            printf("leaf\n");
        else
            printf("internal node\n");
    }
}
