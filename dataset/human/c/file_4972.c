#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define NIL -1
#define N 2
typedef struct {
    int parent,left,right;
}node;
node t[MAX];
int n,d[MAX],h[MAX];

void getdepth(int u,int p){
    d[u]=p;
    if(t[u].right!=NIL)getdepth(t[u].right,p+1);
    if(t[u].left!=NIL)getdepth(t[u].left,p+1);
}

int setheight(int u){
  int h1=0,h2=0;
  if(t[u].right!=NIL)h1=setheight(t[u].right)+1;
  if(t[u].left!=NIL)h2=setheight(t[u].left)+1;
  if(h1>h2)h[u]=h1;
  else h[u]=h2;
  return h[u];
}

int main(){                                                                                  
  int i,id,k,*c,j,df,de,s;                                                                   
  scanf("%d",&n);                                                                      
  for(i=0;i<n;i++) t[i].parent=t[i].left=t[i].right=NIL;                                     
  for(i=0;i<n;i++){                                                                          
    scanf("%d",&id);                                                                    
    c=(int*)malloc(sizeof(int)*N);                                                           
    for(j=0;j<N;j++)scanf("%d",&c[j]);                                                                                                                       
    for(j=0;j<N;j++)t[c[j]].parent=id;
    t[id].right=c[1];
    t[id].left=c[0];                         
  } 

  for(i=0;i<n;i++)if(t[i].parent==NIL)df=i;                                                                                                                                                                                      
  getdepth(df,0); 
  k=setheight(df);                                                                              
  for(i=0;i<n;i++){  
    if(t[i].left!=NIL)de++; 
    if(t[i].right!=NIL)de++;
    for(j=0;j<n;j++){
      if(t[i].parent==NIL)s=NIL;
      else if(t[i].parent==t[j].parent&&i!=j){
        s=j;
        break;
      }
      else s=NIL;
    }                                                                     
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,t[i].parent,s,de,d[i],h[i]);                         
    if(d[i]==0)printf("root\n");                                                                                                          
    else if(t[i].left!=NIL||t[i].right!=NIL)printf("internal node\n");                                                                                
    else printf("leaf\n"); 
    de=0;
  }  
  return 0;                                                                                  
}
