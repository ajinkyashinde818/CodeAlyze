#include<stdio.h>
#define MAX 100000
#define NIL -1


typedef struct{
  int parent;
  int left;
  int right;
}Node;

Node T[MAX];

int n;

int getDep(int u){

  int d=0;
  while(T[u].parent!=NIL){
    u=T[u].parent;
    d++;
  }
  return d;
}

void print(int u){

  int i,c;

  printf("node %d: parent = %d, depth = %d, ",u,T[u].parent,getDep(u));

  if(T[u].parent==NIL) printf("root, ");
  else if(T[u].left==NIL) printf("leaf, ");
  else printf("internal node, ");

  printf("[");\

  for(c=T[u].left,i=0;c!=NIL;c=T[c].right,i++){
    
    if(i!=0)printf(", ");
    printf("%d",c);

  }
  printf("]\n");
}


int main(){
  int kazu,i,j,jisuu,setten,l,d,r;
  
  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].parent=T[i].left=T[i].right=NIL;
  
  for(i=0;i<n;i++){
    scanf("%d%d",&setten,&jisuu);

    for(j=0;j<jisuu;j++){      
      scanf("%d",&kazu);
      
      if(j==0) T[setten].left=kazu;
      else T[l].right=kazu;

      l=kazu;
      T[kazu].parent=setten;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].parent==NIL) r=i;
  }

  
  for(i=0;i<n;i++){
    print(i);
  }

  return 0;
  
}
