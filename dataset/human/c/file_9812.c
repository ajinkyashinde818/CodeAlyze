#include <stdio.h>

typedef struct{
    int parent;
    int depth;
    int l,r;
}Node;

Node node[100001];
int rec(int,int);

int main(){
    int n,k;
    int id,c,l,r,a;
    int i,j;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        node[i].parent = node[i].l = node[i].r = -1;
    }
    for(i=0;i<n;i++){
        scanf("%d%d",&id,&k);
        for(j=0;j<k;j++){
            scanf("%d",&c);
            if(j==0) node[id].l=c;
            else node[l].r = c;
            l=c;
            node[c].parent = id;
        }
    }
    for(i=0;i<n;i++) if(node[i].parent == -1) r=i;
    rec(r,0);

    for(i=0;i<n;i++){
        printf("node %d: parent = %d, depth = %d, ",i,node[i].parent,node[i].depth);
        if(node[i].parent==-1)printf("root, ");
        else if(node[i].l!=-1) printf("internal node, ");
        else printf("leaf, ");
        printf("[");
        if(node[i].l!=-1){
            printf("%d",node[i].l);
            a = node[i].l;
            while(1){
                if(node[a].r == -1) break;
                else printf(", %d",node[a].r);
                a = node[a].r;
            }
        }
        printf("]\n");
    }
    return 0;
}

int rec(int r,int p){
    node[r].depth = p;
    if(node[r].r!=-1) rec(node[r].r,p);
    if(node[r].l!=-1) rec(node[r].l,p+1);
}
