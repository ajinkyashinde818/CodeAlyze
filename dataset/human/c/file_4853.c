#include<stdio.h>
#define N 25
#define NIL -1

struct Node {
  int parent;
  int left;
  int right;
};
struct Node T[N];
int cnt,x,y;

int depth(int nodeid) {

 if(T[nodeid].parent == NIL) {
    return 0;
  }
 else {
      cnt++;
      depth(T[nodeid].parent);
    }
 return  cnt;  
}

int height(int nodeid) {
  int x=0,y=0;
  if(T[nodeid].left != NIL)
    x = height(T[nodeid].left) + 1;
  
  if(T[nodeid].right != NIL)
    y = height(T[nodeid].right) + 1;
  
  if(x < y) return y;
  
  else return x; 
  
}

int sibling(int nodeid) {
  if(T[nodeid].parent == NIL)
    return NIL;

 else  if(T[T[nodeid].parent].left == nodeid)
    return T[T[nodeid].parent].right;

 else return T[T[nodeid].parent].left;

}		 

int degree(int nodeid) {
  if(T[nodeid].left == NIL && T[nodeid].right == NIL)
    return 0;
  else if(T[nodeid].left != NIL && T[nodeid].right != NIL)
    return 2;
  else return 1;
}

int main(void) {
  
  int i,j,n,m,l,newnode,left,right;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    T[i].parent = T[i].left = T[i].right = NIL; 
  
  for(i=0;i<n;i++) {
    scanf("%d%d%d",&newnode,&m,&l);

    T[m].parent = newnode;
    T[l].parent = newnode;  
    T[newnode].left = m;    
    T[newnode].right = l;  
 
  }   
    for(i=0;i<n;i++) { 
      cnt = 0;
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,",i,T[i].parent,sibling(i),degree(i),depth(i),height(i));
      
      if(T[i].parent == NIL) {
	printf(" root\n");
      }
      else if (T[i].left == NIL && T[i].right == NIL) {
	printf(" leaf\n");
      }  
      else  {
	printf(" internal node\n");
      }   
    }
    return 0;    

}
