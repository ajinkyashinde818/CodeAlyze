#include <stdio.h>
#define N 25

typedef struct Node{
    int key;
    int light;
    int left;
    int parent;
}node;

node tree[N];

int FindRoot(int num){
    int i;
    for(i=0; i<num; i++){
        if(tree[i].parent == -1) return i;
    }
}

int CalcDegree(int i){
    int deg = 0;
    if(tree[i].left != -1) deg++;
    if(tree[i].light != -1) deg++;
    return deg;
}

int CalcDepth(int i, int root){
    int dep = 0;
    while(i != root){
        dep++;
        i = tree[i].parent;
    }
    return dep;
}

int CalcHeight(int i,int h){
    int rh=0,lh=0;
    if(tree[i].light == -1 && tree[i].left == -1){
        return h; 
    }else{
        if(tree[i].left != -1){
            lh = CalcHeight(tree[i].left,h+1);
        }
        if(tree[i].light != -1){
            rh = CalcHeight(tree[i].light,h+1);
        }
        if(lh<rh) return rh;
        else return lh;
    }
}

int Sibling(int i){
    if(tree[i].parent == -1){
        return -1;
    }else if(tree[i].key == tree[tree[i].parent].left){
        return tree[tree[i].parent].light;
    }else{
        return tree[tree[i].parent].left;
    }
}

int main(){
    int i,num,buf,root;

    for(i=0; i<N; i++){
        tree[i].parent = -1;
    }
    scanf("%d",&num);
    for(i=0; i<num; i++){
        scanf("%d",&buf);
        scanf("%d %d",&tree[buf].left, &tree[buf].light);
        tree[buf].key = buf;
        if(tree[buf].left != -1)tree[tree[buf].left].parent = tree[buf].key;
        if(tree[buf].light != -1)tree[tree[buf].light].parent = tree[buf].key;
    }

    root = FindRoot(num);
    for(i=0; i<num; i++){
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
        i,tree[i].parent,Sibling(i),CalcDegree(i),CalcDepth(i,root),CalcHeight(i,0));

        if(tree[i].parent == -1) printf("root\n");
        else if(tree[i].left == -1 && tree[i].light == -1) printf("leaf\n");
        else printf("internal node\n");
    }
    return 0;
}
