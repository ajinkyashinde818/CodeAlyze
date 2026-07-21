#include <stdio.h>
#include <stdlib.h>

#define N 25
#define NIL -1


typedef struct {
  int pare, sib;
}Node;


int Depth(int);
int Height(int);



Node node[N];
int n = 0;


int main () {
  
  int i, j, k = 0, m = 0, child = 0, x = 0, cnt = 0;

  scanf("%d", &n);


  for(i = 0 ; i < n ; i++) {
    node[i].pare = NIL;
    node[i].sib = NIL;
  }
  
  for(i = 0 ; i < n ; i++){
    
    scanf("%d",&m);

    for(j = 0 ; j < 2 ; j++) {
      scanf("%d",&child);
      if(j == 0) x = child;
      else {
	node[child].sib = x;
	node[x].sib = child;
      }
      node[child].pare = m;
    }
  }


  for(i = 0 ; i < n ; i++) {

    cnt = 0;
    
    printf("node %d: parent = %d, sibling = %d, ", i, node[i].pare, node[i].sib);

    for(j = 0 ; j < n ; j++) {
      if(node[j].pare == i) cnt++; 
    }

    printf("degree = %d, depth = %d, height = %d, ", cnt, Depth(i), Height(i));

    if(node[i].pare == NIL) printf("root\n");
    else if(cnt > 0) printf("internal node\n");
    else printf("leaf\n");
  }
  
  return 0;
}



int Depth(int x) {

  if(node[x].pare == NIL) return 0;
  else return Depth(node[x].pare) + 1;
}


int Height(int x) {
  int i, r = NIL, l = NIL;

  for(i = 0 ; i < n ; i++) {
    if(node[i].pare == x) {
      if(l == NIL) l = Height(i);
      else r = Height(i);
    }
  }
  if(r > l) return r + 1;
  else return l + 1;
}
