#include <stdio.h>
#define NIL -1
int d,P[100005];

int getDepth(int x){
    
    d = 0;
    while(P[x] != NIL){
        
        x = P[x];
        d++;
        
    }
    
    return d;
    
}

int main()
{
    int i,j,m,n,k,c,sum;
    
    scanf("%d",&m);
    
    int L[m],R[m],T[m];
    
    for(i = 0; i < m; i++){
    P[i] = NIL;
    L[i] = NIL;
    R[i] = NIL;
    }
    
    for(i = 0; i < m; i++){
        
        scanf("%d",&n);
        scanf("%d",&k);
        T[i] = k;
        
        for(j = 0; j < k; j++){
            
            scanf("%d",&c);
            P[c] = n;
            if(j==0) L[n] = c;
            else R[sum] = c;
            sum = c;
            
        }
    }
    
    for(i = 0; i < m; i++){
        
        printf("node %d: ",i);
        printf("parent = %d, ",P[i]);
        printf("depth = %d, ",getDepth(i));
        
        if(P[i] == NIL) printf("root, ");
        else if(L[i] == NIL) printf("leaf, ");
        else printf("internal node, ");
        
        printf("[");
        
        for(j = 0, c = L[i]; c != NIL; j++, c = R[c]){
            
            if(j) printf(", ");
            printf("%d",c);
            
        }
        
        printf("]\n");
        
        }
        
    return 0;
}
