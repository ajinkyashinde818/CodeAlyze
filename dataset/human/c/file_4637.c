#include <stdio.h>

#define MAX 200000

#define NIL -1

struct node {
  int parent;
  int left;
  int right;
};


typedef struct node Node;
 
Node T[MAX];

int D[MAX],H[MAX];

int n;


void printTree(int u){ 

  int i, c;
  
  printf("node %d: ",u); 
  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ", getSibling(u));
  printf("degree = %d, ", getDegree(u));
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);
   
 
  if(T[u].parent == NIL)
    { 
      printf("root");
    }
  else if(getDegree(u) == 0)
    { 
      printf("leaf");
    }
  else { 
    printf("internal node");
  }
  printf("\n");
}
 
 
void setDepth(int u, int d){ 

  if(u==NIL) return; 
 
  D[u] = d;
  
  if(T[u].left!=NIL)
    {
      setDepth(T[u].left, d+1); 
    }
  
  if(T[u].right!=NIL)
    {
      setDepth(T[u].right, d+1); 
    }
}

int setHeight(int u){ 

  int l_height=0, r_height=0;
 
  if(T[u].left != NIL)
    {
      l_height = setHeight(T[u].left) + 1;
    }
  
  if(T[u].right != NIL)
    {
      r_height = setHeight(T[u].right) + 1;
    }

  if(l_height > r_height)
    {
      H[u] = l_height;
    }
  else{
    H[u] = r_height;
  }
  return H[u];
}

int getSibling(int u) {

  if(T[u].parent == NIL)
    {
      return NIL;
    }

  if(T[T[u].parent].left != u && T[T[u].parent].left != NIL)
    {
      return T[T[u].parent].left;
    }
  
  if(T[T[u].parent].right != u && T[T[u].parent].right != NIL)
    {
      return T[T[u].parent].right;
    }
  return NIL;
}
 
int getDegree(int u) {

  int cnt=0;
  
  if(T[u].left != NIL)
    {
      cnt++;
    }
  
  if(T[u].right != NIL)
    {
      cnt++;
    }
  return cnt;
}



int main(){
  int i,j,key,left,right;
  int root = 0;
   
  scanf("%d",&n);
   
  for(i = 0;i < n;i ++)
    { 
      T[i].parent = NIL;
      T[i].left = NIL;
      T[i].right = NIL;
    }
  
  for(i = 0;i < n;i ++)
    {
      scanf("%d", &key);
      scanf("%d%d",&left, &right);
      T[key].left = left;
      T[key].right = right;
 
      if(left != NIL)
	{
	  T[left].parent = key;
	}
    
      if(right != NIL)
	{
	  T[right].parent = key;
	}
    }
  
  for(i = 0;i < n;i ++)
    {
      if(T[i].parent == NIL)
	{
	  root = i;
	}
    }
 
  setDepth(root, 0);
   
  setHeight(root);
 
  for(i = 0;i < n;i ++)
    {
      printTree(i);
    }
 
  return 0;
}
