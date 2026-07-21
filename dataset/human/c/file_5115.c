#include <stdio.h>

typedef struct{
    int id,parent,depth;
    int l,r;
    int sib,height;
}Node;

Node node[200000];

int dfs(int,int);

int main(){
    int i,j,k;
    int N;
    int id,l,r;
    int deg,root;

    scanf("%d",&N);
    for(i=0;i<N;i++) node[i].parent = node[i].l = node[i].r = node[i].sib = -1;

    for(i=0;i<N;i++){
        scanf("%d%d%d",&id,&l,&r);
        node[id].id = id;
        node[id].l = l;
        node[id].r = r;
        if(l!=-1){
            node[l].parent = id;
            node[l].sib = r;
        }
        if(r!=-1){
            node[r].parent=id;
            node[r].sib=l;
        }
    }

    for(i=0;i<N;i++) if(node[i].parent == -1) root=i;
    dfs(root,0);

    for(i=0;i<N;i++){
        deg = (node[i].l!=-1) + (node[i].r!=-1);
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",node[i].id,node[i].parent,node[i].sib,deg,node[i].depth,node[i].height);
        if(node[i].parent==-1) printf("root\n");
        else if(node[i].l == -1 && node[i].r == -1) printf("leaf\n");
        else printf("internal node\n");
    }
    return 0;
}

int dfs(int pos,int dep){
     node[pos].depth = dep;
     int a=0,b=0;
     if(node[pos].l!=-1) a=dfs(node[pos].l,dep+1);
     if(node[pos].r!=-1) b=dfs(node[pos].r,dep+1);
     node[pos].height = a<b? b:a;
     return node[pos].height+1;
 }
