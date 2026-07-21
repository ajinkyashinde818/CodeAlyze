#include<stdio.h>
#include<stdlib.h>

#define N 100000

typedef struct {
    int p,k,dep;
    int *c;
} Node;


int main(){
    int i,j,n,id;
    Node T[N],tmp;
    
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        T[i].p = -1;
        T[i].dep = 0;
    }
    
    for(i=0; i<n; i++){
        scanf("%d",&id);
        scanf("%d",&T[id].k);
        T[id].c = (int *)malloc(sizeof(int)*T[id].k);
        
        for(j=0; j<T[id].k; j++){
            scanf("%d",&T[id].c[j]);
            T[T[id].c[j]].p = id;
        }
    }
    
    for(i=0; i<n; i++){
        tmp = T[i];
        
        while(1){
            if(tmp.p==-1) break;
            T[i].dep++;
            tmp = T[tmp.p];
        }
    }
    
    for(i=0; i<n; i++){
        if(T[i].dep==0){
            printf("node %d: parent = %d, depth = %d, root, [",i,T[i].p,T[i].dep);
            for(j=0; j<T[i].k-1; j++) printf("%d, ",T[i].c[j]);
            if(T[i].k!=0) printf("%d]\n",T[i].c[j]);
            else printf("]\n");
        }
        
        else if(T[i].k!=0 && T[i].p!=-1){
            printf("node %d: parent = %d, depth = %d, internal node, [", i,T[i].p,T[i].dep);
            for(j=0; j<T[i].k-1; j++) printf("%d, ", T[i].c[j]);
            printf("%d]\n",T[i].c[j]);
        }
        
        else if(T[i].k==0) printf("node %d: parent = %d, depth = %d, leaf, []\n",i,T[i].p,T[i].dep);
    }
    
    return 0;
}
