#include <stdio.h>
struct data{
    int par;
    int son;
    int sib;
};
typedef struct data node;

node tree[100000];
int main(){
    int n,i,j,cur,cur_n,m,par,dep=0;
    for(i=0;i<100000;i++){
        tree[i].par=-1;
        tree[i].son=-1;
        tree[i].sib=-1;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&cur,&cur_n);
        par=cur;
        for(j=0;j<cur_n;j++){
            scanf("%d",&m);
            if(j){
                tree[cur].sib=m;
            }
            else{
                tree[cur].son=m;
            }
            cur=m;
            tree[cur].par=par;         
        }
    }
    /*
    for(i=0;i<n;i++){
        printf("%d   %d %d %d\n",i,tree[i].par,tree[i].sib,tree[i].son);
    }
    */

    for(i=0;i<n;i++){
        printf("node %d: parent = %d, ",i,tree[i].par);
        cur=i;
        while(1){
            if(tree[cur].par==-1) break;
            dep++;
            cur=tree[cur].par;
        }
        cur=i;
        printf("depth = %d, ",dep);
        dep=0;
        if(tree[cur].son==-1 && n!=1){
            printf("leaf, []\n");
        }
        else{
            if(tree[cur].par==-1){
                printf("root, ");
            }
            else{
                printf("internal node, ");
            }
            m=tree[cur].son;
            printf("[");
            while(n!=1){
                printf("%d",m);
                m=tree[m].sib;
                if(m==-1) break;
                printf(", ");
            }
            printf("]\n");
        }
    }
    return 0;
}
