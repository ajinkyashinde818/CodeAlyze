#include <stdio.h>
struct data{
    int par;
    int left;
    int right;
};
typedef struct data node;
void postParse(int);
node tree[100000];
int max,tmp;
int main(){
    int n,i,j,cur,cur_n,m=0,par,dep=0;
    for(i=0;i<100000;i++){
        tree[i].par=-1;
        tree[i].left=-1;
        tree[i].right=-1;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&cur);
        scanf("%d %d",&tree[cur].left,&tree[cur].right);
        tree[tree[cur].left].par=cur;
        tree[tree[cur].right].par=cur;
    }
    /*
    for(i=0;i<n;i++){
        printf("%d   %d %d %d\n",i,tree[i].par,tree[i].sib,tree[i].son);
    }
    */

    for(i=0;i<n;i++){
        printf("node %d: parent = %d, ",i,tree[i].par);
        cur=i;
        if(tree[cur].par==-1){
            printf("sibling = -1, ");
        }
        else{
            if(tree[tree[cur].par].left==cur){
                printf("sibling = %d, ",tree[tree[cur].par].right);
            }
            else{
                printf("sibling = %d, ",tree[tree[cur].par].left);
            }    
        }
        if(tree[cur].left!=-1) m++;
        if(tree[cur].right!=-1) m++;
        printf("degree = %d, ",m);
        while(1){
            if(tree[cur].par==-1) break;
            dep++;
            cur=tree[cur].par;
        }
        cur=i;
        printf("depth = %d, ",dep);
        dep=0;
        m=0;
        tmp=-1;
        max=-1;
        postParse(cur);
        printf("height = %d, ",max);
        if(tree[cur].par==-1){
            printf("root\n");
        }
        else if(tree[cur].right==-1 && tree[cur].left==-1){
            printf("leaf\n");
        }
        else{
            printf("internal node\n");
        }
    }
    return 0;
}

void postParse(int u){
    tmp++;
    if(u==-1){
        tmp--;
        if(max<tmp)max=tmp;
        return;
    }
    postParse(tree[u].left);
    postParse(tree[u].right);
    tmp--;
}
