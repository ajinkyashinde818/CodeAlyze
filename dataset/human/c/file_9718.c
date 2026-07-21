#include <stdio.h>
#define MAX 100001
#define NIL -1

struct Node{
  int p;
  int l;
  int r;
};

struct Node T[MAX];
int n;
int D[MAX];

void print(int);
void Depth(int,int);


int main(int argc, char const *argv[]) {

  int i,j,d,v,c,l,r;

  scanf("%d",&n);

  // ?????????
  for( i = 0 ; i < n ; i++ ){
    T[i].p = T[i].l = T[i].r = NIL;
  }

  // ??\???
  for( i = 0 ; i < n ; i++ ){

    scanf("%d %d",&v,&d);

    for( j = 0 ; j < d ; j++ ){
      scanf("%d",&c);
      if( j == 0 ){
        T[v].l = c;
      }else{
        T[l].r = c;
      }
      l = c;
      T[c].p = v;
    }

  }

  for( i = 0 ; i < n ; i++ ){
    if( T[i].p == NIL ){
      r = i;
    }
  }


  Depth(r,0);

  for( i = 0 ; i < n ; i++ ){
    print(i);
  }

  return 0;
}

void print(int i){

  int c;

  printf("node %d: ",i);
  printf("parent = %d, ",T[i].p);
  printf("depth = %d, ",D[i]);

  if( T[i].p == NIL ){
    printf("root, ");
  }else if( T[i].l == NIL ){
    printf("leaf, ");
  }else{
    printf("internal node, ");
  }

  printf("[");
  c = T[i].l;

  while( c != NIL ){
    if( c == T[i].l ){
      printf("%d",c);
    }else{
      printf(", %d",c);
    }
    c = T[c].r;
  }
  printf("]\n");

}


void Depth(int i, int dep){
  D[i] = dep;
  if( T[i].r != NIL ){
    Depth(T[i].r,dep);
  }

  if( T[i].l != NIL ){
    Depth(T[i].l,dep+1);
  }

}
