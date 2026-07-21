#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define NIL -1
typedef struct {
    int parent,left,right;
}node;
node t[MAX];
int n,*d;

void getdepth(int u,int p){
    d[u]=p;
    if(t[u].right!=NIL)getdepth(t[u].right,p);
    if(t[u].left!=NIL)getdepth(t[u].left,p+1);
}

int main(){                                                                                  
  int i,id,k,*c,j,df;                                                                   
  scanf("%d",&n);  
  d=(int*)malloc(sizeof(int)*n);                                                                       
  for(i=0;i<n;i++) t[i].parent=t[i].left=t[i].right=NIL;                                     
  for(i=0;i<n;i++){                                                                          
    scanf("%d%d",&id,&k);                                                                    
    c=(int*)malloc(sizeof(int)*k);                                                           
    for(j=0;j<k;j++)scanf("%d",&c[j]);                                                                                                                       
    for(j=0;j<k;j++){                                                                        
      t[c[j]].parent=id;
      if(j==k-1)t[c[j]].right=NIL;
      else t[c[j]].right=c[j+1];                                                                  
    }                           
    t[id].left=c[0];
    if(k==0)t[id].left=NIL;
  }     
  for(i=0;i<n;i++)if(t[i].parent==NIL)df=i;                                                                                                                                                                                      
getdepth(df,0);                                                                               for(i=0;i<n;i++){                                                                        
    printf("node %d: parent = %d, depth = %d, ",i,t[i].parent,d[i]);                         
    if(d[i]==0){                                                                           
        printf("root, ");                                                                    
        k=t[i].left;                                                                       
        printf("[");                                                                     
        while(k!=NIL){                                                                      
          printf("%d",k);
          k=t[k].right;
          if(k==NIL)break;
          printf(", ");                                                                                                                                      
        }                                                                                    
        printf("]\n");                                                                       
      }                                                                                      
      else if(t[i].left!=NIL){                                                                      
        printf("internal node, ");                                                           
        k=t[i].left;                                                                       
        printf("[");                                                                     
        while(k!=NIL){                                                                     
          printf("%d",k);
          k=t[k].right;
          if(k==NIL)break;
          printf(", ");                                                                                                                                     
        }                                                                                    
        printf("]\n");                                                                       
      }                                                                                      
      else if(t[i].left==NIL)printf("leaf, []\n"); 
        }                                                                                        
  return 0;                                                                                  
}
