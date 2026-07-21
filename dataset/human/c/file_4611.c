#include<stdio.h>
#define MAX 100000
#define MIN -1

struct Node{
  int parent, left, right;
};

struct Node T[MAX];
int D[MAX], H[MAX];

int Depth(int);
int Sibling(int);
void print(int);


int main(){
  int i,n, x,y,z,a,b;
  
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    T[i].parent=MIN;
  }

  for ( i = 0; i < n; i++ ){
    scanf("%d%d%d",&x,&y,&z);
    T[x].left=y;
    T[x].right=z;
    if (y!=MIN) T[y].parent=x;
    if (z!=MIN) T[z].parent=x;
  }

  for ( i = 0; i < n; i++ ){
    D[i]=Depth(i);
    H[i]=0;
  }

  for ( i = 0; i < n; i++ ){
    if ( T[i].left==MIN&&T[i].right==MIN) { 
      H[i]=0;
       a = T[i].parent;
       b = 1;
      while(1){
	if (a==MIN) break;
	if ( H[a] < b ) H[a]=b;
	b++;
	a = T[a].parent;
      }
    }
  }

  for ( i = 0; i < n; i++ ){
    print(i);
  }
  return 0;
}

int Depth(int u){
  int d=0;
  while(T[u].parent!=MIN){
    u=T[u].parent;
    d++;
  }
  return d;
}

int Sibling(int u){
  if ( T[u].parent==MIN) return MIN;
  if ( T[T[u].parent].left!=u&&T[T[u].parent].left!=MIN) return T[T[u].parent].left;
  if ( T[T[u].parent].right!=u&&T[T[u].parent].right!=MIN) return T[T[u].parent].right;
  return MIN;
}

void print(int u){
  int count=0;
  printf("node %d: ", u);

  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ", Sibling(u));
  if ( T[u].left!=MIN) {
    count++;
  }
  if ( T[u].right!=MIN){
    count++;
  }
  printf("degree = %d, ", count);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);

  if ( T[u].parent==MIN){
    printf("root\n");
  } else if ( T[u].left==MIN&&T[u].right==MIN){
    printf("leaf\n");
  } else {
    printf("internal node\n");
  }
}
