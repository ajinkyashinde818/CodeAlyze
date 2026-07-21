#include <stdio.h>

#define NODEMAX 25

typedef struct {
  int parent;
  int left;
  int right;
} Node;

int measureheight(Node *,int,int);

int main()
{
  int i, j, n, id, sibling, degree, depth, height;
  Node T[NODEMAX];

  
  scanf("%d",&n);
  
  for(i = 0; i < n; i++) {
    T[i].parent = -1;
  }
  
  for(i = 0; i < n; i++) {
    scanf("%d",&id);
    scanf("%d%d",&T[id].left,&T[id].right);
    T[T[id].left].parent = id;
    T[T[id].right].parent = id;
  }
  
  for(i = 0; i < n; i++) {

    /*sibling*/
    id = T[i].parent;
    if(id < 0) {
      sibling = -1;
    }
    else if(T[id].left == i) sibling = T[id].right;
    else sibling = T[id].left;

    /*degree*/
    degree = 0;
    if(T[i].left >= 0) degree++;
    if(T[i].right >= 0) degree++;

    /*depth*/
    depth = 0;
    id = i;
    while(T[id].parent >= 0) {
      id = T[id].parent;
      depth++;
    }

    /*height*/
    height = measureheight(T,i,0);

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, T[i].parent, sibling, degree, depth, height);

    if(T[i].parent < 0) printf("root");
    else if(degree == 0) printf("leaf");
    else printf("internal node");

    printf("\n");
  }

  return 0;
}

int measureheight(Node * T, int id, int height)
{
  int lefth, righth;
  if(id >= 0) {
    lefth = measureheight(T,T[id].left,height+1);
    righth = measureheight(T,T[id].right,height+1);
    if(lefth > righth) return lefth;
    else return righth;
  }
  return height-1;
}
