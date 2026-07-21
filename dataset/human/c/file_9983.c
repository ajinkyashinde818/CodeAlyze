#include <stdio.h>

#define MAX 100000

int n,D[MAX];

typedef struct node {
  int item;
  int left;
  int right;
} Node;

Node T[MAX];

/*
int getdepth(int u){

  int d=0;

  while(T[u].parent!=-1){

    u=T[u].parent;

    d++;
  }
  return d;
}
*/

void print(int u){

  int i,j=0,c;

  printf("node %d: parent = %d, depth = %d, ", u,T[u].item,D[u]);

  if(T[u].item==-1) printf("root, ");
  else if(T[u].left==-1) printf("leaf, ");
  else printf("internal node, ");

  printf("[");    

  for(i=0, c=T[u].left; c!=-1; i++, c=T[c].right){

    if(i) printf(", ");
	
    printf("%d",c);
  }
   
  printf("]");

}

int setdepth(int u,int p){
  
  D[u]=p;

  if(T[u].right!=-1){

    setdepth(T[u].right,p);
  }

  if(T[u].left!=-1){

    setdepth(T[u].left,p+1);
  }

}


int main(){

  int i,j,d,v,r,l,c;

  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].item=T[i].left=T[i].right=-1;


  for(i=0;i<n;i++){

    scanf("%d%d",&v,&d);

    for(j=0;j<d;j++){

      scanf("%d",&c);

      if(j==0) T[v].left=c;
      else T[l].right=c;

      l=c;
      T[c].item=v;
      
     
    }

  }
  for(i=0;i<n;i++){

    if(T[i].item==-1) r=i;
  }

  setdepth(r, 0);

  for(i=0;i<n;i++){
    print(i);
    printf("\n");
  }
  
  return 0;

}
