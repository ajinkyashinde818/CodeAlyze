#include<stdio.h>
#define N 100000
#define M -1


struct Node{
  int parent;
  int left;
  int right;
};
struct Node T[N];
int count=0;
 
int depth(int nodeid) {
  if(T[nodeid].parent == M) {
    return count;
  }
  else {
 count++;
 return depth(T[nodeid].parent);
  }
}
 
void degree(int nodeid) {
  if(nodeid != M) {
    if(count != 0){
      printf(", ");
    }
    printf("%d",nodeid);
    count++;
    degree(T[nodeid].right);
  }
}  

main(){

  int i,j,n,m,newnode,child,left,right;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    T[i].parent = T[i].left = T[i].right = M;
 
  for(i=0;i<n;i++) {
    scanf("%d%d",&newnode,&m);
    for(j=0;j<m;j++) {
      scanf("%d",&child);
      T[child].parent = newnode;
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
    count = 0;
    printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,depth(i));
    if(T[i].parent == M) {
      printf("root, [");
    }
    else if (T[i].left == M) {
      printf("leaf, [");
    } 
    else  {
      printf("internal node, [");
    }   
    count=0;
    degree(T[i].left);
    printf("]\n");
  }
  return 0;

}
