#include<stdio.h>

#define MAX 100000

typedef struct {
  int parent,left,right;
} Node;

Node T[MAX];
int D[MAX];
int n;

void get(int u);
void depth(int u,int p);

int NIL = -1;


int main(void){
  int i,j;
  int l,r;
  int p,q,c;
  
  scanf("%d",&n);
  
  for(i = 0;i < n;i++){
    T[i].left = NIL;
    T[i].right = T[i].left;
    T[i].parent = T[i].right;
  }

  for(i = 0;i < n;i++){
    scanf("%d %d",&p,&q);
    for(j = 0;j < q;j++){
      scanf("%d",&c);
      if(j == 0){
	T[p].left = c;
      } else {
	T[l].right = c;
      }
      l = c;
      T[c].parent = p;
    }
  }
  
    for(i = 0;i < n;i++){
      if(T[i].parent == NIL){
	r = i;
      }
    }

    depth(r,0);

    for(i = 0;i < n;i++){
      get(i);
    }

      return 0;
    }



void get(int u){
  int i = 0;
  int d;
  
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("depth = %d, ",D[u]);

  if(T[u].parent == NIL){
    printf("root, ");
  } else if(T[u].left == NIL){
    printf("leaf, ");
  } else {
    printf("internal node, ");
  }

  putchar('[');

  for(d = T[u].left;d != NIL;d = T[d].right,i++){
    
    if(i != 0){
      printf(", ");
    }
    printf("%d",d);
  }
  puts("]");
}


void depth(int u,int p){
  D[u] = p;

  if(T[u].left != NIL){
    depth(T[u].left,p+1);
  }  
  if(T[u].right != NIL){
    depth(T[u].right,p);
  }
}
