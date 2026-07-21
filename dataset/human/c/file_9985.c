#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define NIL -1

typedef struct {
  int pare, left, right;
}Node;

int Depth(int);
void Childprint(int);

Node node[N];

int main () {
  int i, j, n = 0, m = 0, k = 0, child = 0, sib = 0;

  

  scanf("%d",&n);


  for(i = 0 ; i < n ; i++) {
    node[i].pare = NIL;
    node[i].left = NIL;
    node[i].right = NIL;
  }

  for(i = 0 ; i < n ; i++) {

    scanf("%d",&m);
    
    scanf("%d",&k);

    sib = NIL;
    for(j = 0 ; j < k ; j++) {
      scanf("%d",&child);
      node[child].pare = m;
      if(j == 0) node[m].left = child;
      else node[sib].right = child;
      sib = child;
 
    }  
  }

  for(i = 0 ; i < n ; i++) {
    printf("node %d: parent = %d, depth = %d, ", i, node[i].pare ,Depth(i));
    
    if(node[i].pare == NIL) {
      printf("root, ");
      Childprint(i);
    }

    else if(node[i].left == NIL) {
      printf("leaf, []\n");
    }

    else {
      printf("internal node, ");
      Childprint(i);
    }
  }

  return 0;
}


void Childprint(int x) {

  int c = 0;

  printf("[");

  for(c = node[x].left ; c != NIL ; c = node[c].right) {

    if(node[c].right == NIL) printf("%d",c);
    else printf("%d, ",c);
    
  }

  printf("]\n");
}


int Depth(int x) {

  if(node[x].pare == NIL) return 0;

  else return Depth(node[x].pare) + 1;
}
