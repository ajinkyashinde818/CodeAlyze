#include <stdio.h>
#include <stdlib.h>
int getdepth(int);
void print(int);
struct Node{
    int parent,left,right;
};
struct Node T[100000];
int count=0;
int d=0;
int main(){
    int n,i,j,node,k,child,l;
    
        scanf("%d",&n);
    
    for(i=0;i<n;i++){
        T[i].parent=-1;
        T[i].left=-1;
        T[i].right=-1;
    }
    for(i=0;i<n;i++){
        scanf("%d%d",&node,&k);
        for(j=0;j<k;j++){
            scanf("%d",&child);
            
            if(j==0){
                T[node].left=child;
            }
            else{
                T[l].right=child;
            }
            l=child;
            T[child].parent=node;
        }
    }
    for(i=0;i<n;i++){
        d=0;
        printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,getdepth(i));
        if(T[i].parent==-1){
            printf("root, [");
        }
        else if(T[i].left==-1)printf("leaf, [");
        else{
            printf("internal node, [");
        }
        print(T[i].left);
        count=0;
        printf("]\n");
    }
    return 0;
}
int getdepth(int a){
    while(T[a].parent!=-1){
        a=T[a].parent;
        d++;
    }
    return d;
}
void print(int t){
    if(t!=-1){
        if(count!=0){
            printf(", ");
        }
        count++;
        printf("%d",t);
        print(T[t].right);
    }
}
