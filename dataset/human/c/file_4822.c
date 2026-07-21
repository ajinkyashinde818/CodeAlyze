#include <stdio.h>

typedef struct{
    int id;
    int parent;
    int sibling;
    int degree;
    int depth;
    int height;
}Tree;

int main(){
    int i,j,n,depmax=0,depth;
    int id,data;
    scanf("%d",&n);
    Tree T[n];
    for(i=0;i<n;i++){
        T[i].id=-1;
        T[i].parent=-1;
        T[i].sibling=-1;
        T[i].degree=0;
        T[i].depth=0;
        T[i].height=0;
    }
    
    
    for(i=0;i<n;i++){
        scanf("%d",&id);
        T[id].id=id;
        scanf("%d",&data);
        if(data!=-1){
            T[id].degree++;
            T[data].parent=id;
        }
        scanf("%d",&data);
        if(data!=-1){
            T[id].degree++;
            T[data].parent=id;
        }
    }
    
    //get status
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(T[i].parent==T[j].parent&&i!=j){
                T[i].sibling=j;
                T[j].sibling=i;
            }
        }
        data=i;
        depth=0;
        while(T[data].parent!=-1){
            depth++;
            data=T[data].parent;
            if(T[data].height<depth)T[data].height=depth;
        }
        T[i].depth=depth;
        
    }
    
    
    for(i=0;i<n;i++){
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,",i,T[i].parent,T[i].sibling,T[i].degree,T[i].depth,T[i].height);
        if(T[i].parent==-1)printf(" root\n");
        else if(T[i].degree==0)printf(" leaf\n");
        else printf(" internal node\n");
        
    }
    return 0;
}
