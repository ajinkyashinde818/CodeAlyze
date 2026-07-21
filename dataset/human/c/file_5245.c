#include <stdio.h>

typedef struct{
    int id;
    int parent;
    int sibling;
    int degree;
    int depth;
    int height;
}node;

int main(){
    int i,j,n,depmax=0,depth;
    int id,b;
    scanf("%d",&n);
    node ha[n];
    for(i=0;i<n;i++){
        ha[i].id=-1;
        ha[i].parent=-1;
        ha[i].sibling=-1;
        ha[i].degree=0;
        ha[i].depth=0;
        ha[i].height=0;
    }
    
    
    for(i=0;i<n;i++){
        scanf("%d",&id);
        ha[id].id=id;
        scanf("%d",&b);
        if(b!=-1){
            ha[id].degree++;
            ha[b].parent=id;
        }
        scanf("%d",&b);
        if(b!=-1){
            ha[id].degree++;
            ha[b].parent=id;
        }
    }
    
    //get status
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(ha[i].parent==ha[j].parent&&i!=j){
                ha[i].sibling=j;
                ha[j].sibling=i;
            }
        }
        b=i;
        depth=0;
        while(ha[b].parent!=-1){
            depth++;
            b=ha[b].parent;
            if(ha[b].height<depth)ha[b].height=depth;
        }
        ha[i].depth=depth;
        
    }
    
    
    for(i=0;i<n;i++){
        printf("node %d: ",i);
	printf("parent = %d, ",ha[i].parent);
	printf("sibling = %d, ",ha[i].sibling);
	printf("degree = %d, ",ha[i].degree);
	printf("depth = %d, ",ha[i].depth);
	printf("height = %d,",ha[i].height);
        if(ha[i].parent==-1)printf(" root\n");
        else if(ha[i].degree==0)printf(" leaf\n");
        else printf(" internal node\n");
        
    }
    return 0;
}
