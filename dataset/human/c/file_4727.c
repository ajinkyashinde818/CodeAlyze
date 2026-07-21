#include<stdio.h>
#define MAX 100000
#define NIL -1
 
struct Node{
  int parent;
  int left;
  int right;
};

struct Node T[MAX];
void Print(int);

int dep;
 
int main(){
  int d, v, c, l, n, tmp;
  int i, j;

    scanf("%d", &n);
       
    for(i=0; i<n; i++){
	  T[i].parent = NIL;
	  T[i].left = NIL;
	  T[i].right = NIL;
    }

    for(i=0; i<n; i++){
      scanf("%d%d%d", &v, &d, &c);
             T[d].parent = v;
			 T[c].parent = v;
             T[v].left = d;
             T[v].right = c;
    }
       
    for(i=0; i<n; i++) Print(i);

    return 0;
}
 
int Depth(int node)
{
  if(T[node].parent == NIL) return 0;
  if(T[node].parent != NIL){
	dep++;
	Depth(T[node].parent);
  }
  return dep;
}

int Degree(int node)
{
    if(T[node].left == NIL && T[node].right == NIL) return 0;
    else if(T[node].left != NIL && T[node].right != NIL) return 2;
    else  return 1;
}

int Sibling(int node){
  if(T[node].parent == NIL) return NIL;
  else if(T[T[node].parent].left == node) return T[T[node].parent].right;
  else return T[T[node].parent].left;
}
  
int Hight(int node)
{
  int hilef = 0, hiri = 0;

  if(T[node].left != NIL) {
	hilef = Hight(T[node].left) +1;
  }
  if(T[node].right != NIL){
	hiri = Hight(T[node].right) +1;
  }
  if(hilef < hiri) return hiri;
  else return hilef;
}
 
   
void Print(int node){
  printf("node %d: ", node);
  printf("parent = %d, ", T[node].parent);
  printf("sibling = %d, ", Sibling(node));
  printf("degree = %d, ", Degree(node));
  dep=0;
  printf("depth = %d, ", Depth(node));
  printf("height = %d, ", Hight(node));
   
  if(T[node].parent == NIL) printf("root\n");
  else if(T[node].left == NIL && T[node].right == NIL) printf("leaf\n");
  else printf("internal node\n");
}
