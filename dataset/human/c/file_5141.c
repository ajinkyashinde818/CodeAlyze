#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r,sib;}; 
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int H[MAX];


void print(int u){
  int i, c,degree;
  printf("node %d: parent = %d, sibling = %d,", u, T[u].p,T[u].sib);
  degree = 0;
  if(T[u].l != NIL)degree++;
  if(T[u].r != NIL)degree++;
    printf(" degree = %d, ",degree);
  

  printf("depth = %d, height = %d, ", D[u], H[u]);
  
  if(T[u].p == NIL) printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL) printf("leaf\n");
  else printf("internal node\n");
  /*
  printf("[");
  for (i=0, c = T[u].l; c != NIL; i++, c = T[c].r){
    if(i) printf(", ");
    printf("%d", c);
  }
  printf("]\n");
*/
  
}

void calcDepth(int u, int p){
  D[u] = p;
  
  if(u != NIL) calcDepth(T[u].l,p + 1);
  if(u != NIL) calcDepth(T[u].r,p + 1);
}

int calcHeight(int u)
{
  int h1 = 0;
  int h2 = 0;
  if(T[u].l != NIL) h1 = calcHeight(T[u].l)+1;
  if(T[u].r != NIL) h2 = calcHeight(T[u].r)+1;

  if(h1> h2) H[u] = h1;
    else  H[u] = h2;

  return H[u];
}

int main(){
  int i, j, k;
  int n;
  int id, sib, child[2];
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = T[i].sib = NIL;
  /*  
  for(i=0; i<n; i++){
    scanf("%d", &id);
    for(j = 0, sib = NIL; j<2; j++){ //子を入力する (input children)
      scanf("%d", &child);
      T[child].p = id;
      if(j == 0) T[id].l = child; //idの一番左の子 (the most left child of id)
      else T[sib].r = child; //左の兄弟に繋げる (connect to left sibling)
      sib = child;//次の子供の左の兄弟 (the left sibling of the next child)
    }
  */
    
for(i=0; i<n; i++){
    scanf("%d", &id);
      scanf("%d %d", &child[0],&child[1]);
      for(j = 0, sib = NIL; j<2; j++){ 
      T[child[j]].p = id;
      
      if(j == 0){
	T[id].l = child[0]; 
	T[child[0]].sib = child[1];
      }
      else {
	T[id].r = child[1]; 
	 T[child[1]].sib = child[0];
      }
      
      sib = child[j];
      }
 }



  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }
  
  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);
  calcHeight(root);

  //出力 (output)
  for(i=0; i<n; i++) print(i);
  
  return 0;
    }
