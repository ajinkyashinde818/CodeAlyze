#include<stdio.h>
#define NIL -1
 
 struct Node{
  int pa;
  int left;
  int right;
};
struct Node T[100001];
int cnt=0;
 int main(void) {
   
  int i,j,n,m,newnode,child,left,right;
   
  scanf("%d",&n);
 
  for(i=0;i<n;i++)
    T[i].pa = T[i].left = T[i].right = NIL;
 
  for(i=0;i<n;i++) {
    scanf("%d%d",&newnode,&m);
    for(j=0;j<m;j++) {
      scanf("%d",&child);
      T[child].pa = newnode;
      if(j != 0) {
    T[left].right = child;
      }
      else {
    T[newnode].left = child;
      }
      left = child;
    }
  }
  for(i=0;i<n;i++) {
    cnt = 0;
    printf("node %d: parent = %d, depth = %d, ",i,T[i].pa,depth(i));
      if(T[i].pa == NIL) {
    printf("root, [");
      }
      else if (T[i].left == NIL) {
    printf("leaf, [");
      } 
      else  {
    printf("internal node, [");
      }   
    cnt=0;
    degree(T[i].left);
    printf("]\n");
  }
  return 0;
}
int depth(int nodeid) {
  if(T[nodeid].pa == NIL) {
    return cnt;
  }
  else {
 cnt++;
 return depth(T[nodeid].pa);
  }
}
 
void degree(int nodeid) {
  if(nodeid != NIL) {
    if(cnt != 0){
      printf(", ");
    }
    printf("%d",nodeid);
    cnt++;
    degree(T[nodeid].right);
  }
}
