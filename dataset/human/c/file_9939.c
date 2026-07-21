#include<stdio.h>
#define MAX 1000000

typedef struct
{         
  int p; //parent
  int l; //left
  int r; //right
}Tree;
Tree A[MAX];   

int depth(int i);

int main(){
  int i,j; 
  int N,id,k,c,l;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    A[i].p=A[i].l=A[i].r=-1;
  }

  for(i=0;i<N;i++){
    scanf("%d%d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      A[c].p=id;
      if(j==0) A[id].l=c;
      else A[l].r=c;
      l=c;
    }
  }

  for(i=0;i<N;i++){
    printf("node %d: parent = %d, depth = %d,",i,A[i].p,depth(i));
    if(depth(i)==0) printf(" root, [");
    else if(A[i].l==-1) printf(" leaf, [");
    else printf(" internal node, [");
    j=A[i].l;
    while(j!=-1){
      printf("%d",j);
      j=A[j].r;
      if(j!=-1) printf(", ");
    }
    printf("]\n");
  } 
      
  return 0;
}

int depth(int i){
  int j=0;
  while(A[i].p!=-1){
    i=A[i].p;
    j++;
  }
  
  return  j;
}
