#include<stdio.h>
#define NIL -1
 
int D[10000],H[10000];
 
struct Node{
  int parent,left,right;
    };
  struct Node T[10000];
void print(int);
int dep;
 
int main(){
  int i,p,r,l,root=0,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d", &p, &l, &r);
    T[l].parent = p;
    T[r].parent = p;
    T[p].left = l;
    T[p].right = r;
    
  }
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}
 
   
int setDepth(int u){
   
    if(T[u].parent == NIL)return 0;
    if(T[u].parent!=NIL){
      dep++;
      setDepth(T[u].parent);
  }
    return dep;
}
 
int setHeight(int u){
  int h1 = 0,h2 = 0;
  if(T[u].left!=NIL){
    h1 = setHeight(T[u].left)+1;
  }
  if(T[u].right!=NIL){
    h2 = setHeight(T[u].right)+1;
  }
  if(h1 > h2) return h1;
  else return h2;
}
 
   
int Sibling(int u){
  if(T[u].parent == NIL) return NIL;
  else if(T[T[u].parent].left!=u && T[T[u].parent].left!=NIL){
    return T[T[u].parent].left;
  }
  else if(T[T[u].parent].right!=u && T[T[u].parent].right!=NIL) {
    return T[T[u].parent].right;
  }
  return NIL;
}
 
void print(int u){
  int deg = 0;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent); 
  printf("sibling = %d, ",Sibling(u));
  if(T[u].right!=NIL) deg++;
  if(T[u].left!=NIL) deg++;
  printf("degree = %d, ",deg);
  dep = 0;
  printf("depth = %d, ",setDepth(u));
  printf("height = %d, ",setHeight(u));
  if(T[u].parent == NIL) printf("root\n");
  else if(T[u].left==NIL && T[u].right==NIL) printf("leaf\n");
  else printf("internal node\n");
}
