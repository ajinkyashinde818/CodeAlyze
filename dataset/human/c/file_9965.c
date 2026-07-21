#include <stdio.h>
#define M_NUM 100000

typedef struct Node{
    int key;
    int parent;
    int child;
    int sibling; 
}node;

node tree[M_NUM];

void Initialize(){
    int i;
    for(i=0; i<M_NUM; i++){
        tree[i].key = -1;
        tree[i].parent = -1;
        tree[i].child = -1;
        tree[i].sibling = -1;
    }
}


short CalcDepth(int i){
    int dep=0;
    int search = i;

    while(tree[search].parent != -1){
        dep++;
        search = tree[search].parent;
    }

    return dep;
}

int main(){
    int i,j,n,degree,num,childl=0,depth,buf;

    Initialize();
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d %d",&num, &degree);
        tree[num].key = num;
        for(j=0; j<degree; j++){
            buf = childl;
            scanf("%d",&childl);
            tree[childl].key = childl;
            tree[childl].parent = tree[num].key;
            if(j==0)tree[num].child = childl;
            if(j!=0)tree[buf].sibling = tree[childl].key;
        }
    }

    for(i=0; i<n; i++){
        buf = tree[i].child;
        depth = CalcDepth(i);
        printf("node %d: parent = %d, depth = %d, ",tree[i].key,tree[i].parent,depth);
        if(tree[i].parent == -1) printf("root");
        else if(tree[i].child == -1) printf("leaf");
        else printf("internal node");
        printf(", [");
        while(buf != -1){
            printf("%d",buf);
            if(tree[buf].sibling != -1) printf(", ");
            buf = tree[buf].sibling;
        }
        printf("]\n");
    }
    return 0;
}
