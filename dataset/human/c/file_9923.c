#include<stdio.h>

#define N 100002
#define NIL -1

typedef struct{
    int l;
    int r;
    int p;
    int k;
    int d;
}Node;
Node node[N];
int dep(int);

int main(){
    int i,j,n,a,b,id,d;
    scanf("%d", &n);
    for(i = 0;i < n;i++){
        node[i].l = NIL;
        node[i].r = NIL;
        node[i].p = NIL;
    }
    for(i = 0;i < n;i++){
        scanf("%d",&id);
        scanf("%d",&node[id].k);
        b = id;
        for(j = 0;j < node[id].k;j++){
            scanf("%d", &a);
            if(j == 0){
                node[b].l = a;
                node[a].p = id;
                b = a;
            }else{
                node[b].r = a;
                node[a].p = id;
                b = a;
            }
        }
    }
    for(i = 0; i < n; i++){
        node[i].d = 0;
        a = node[i].p;
        while(1){
            if(a == NIL){
                break;
            }else{
                a = node[a].p;
                node[i].d++;
            }
        }
    }
    for(i = 0;i < n;i++){
        printf("node %d: parent = %d, depth = %d, ", i, node[i].p,node[i].d);
        if(node[i].l != NIL){
            if(node[i].p != NIL){
                printf("internal node, [");
            }else{
                printf("root, [");
            }
            for(j = 0;j < node[i].k-1;j++){
                if(j == 0){
                    b = node[i].l;
                    printf("%d, ", node[i].l);
                }else{
                    printf("%d, ", node[b].r);
                    b = node[b].r;
                }
            }
            if(node[i].k == 1){
                printf("%d]\n", node[i].l);
            }else{
                printf("%d]\n", node[b].r);
            }
        }else{
            if(node[i].p == NIL){
                printf("root, []\n");
            }
            else{
                printf("leaf, []\n");
            }
        }
    }  
    return 0;
}
