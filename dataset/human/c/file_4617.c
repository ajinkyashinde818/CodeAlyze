#include <stdio.h>
#define N 100000
#define NIL -1

typedef struct node{
  int parent;
  int left;
  int right;
}Node;

Node T[N];

int n;

int Calc_depth(int x){
  if(T[x].parent == NIL) return 0;
  return Calc_depth(T[x].parent) + 1;
}

void type_pri(int y){
  if(T[y].parent == NIL) printf("root");
  else if((T[y].left == NIL) && (T[y].right == NIL)) printf("leaf");
  else printf("internal node");
}

int calc_deg(int z){
  int cnt = 0;
  if(T[z].left != NIL) cnt++;
  if(T[z].right != NIL) cnt++;
  return cnt;
}

int get_height(int i){
  int x = 0,y = 0;
  if(T[i].left == NIL && T[i].right == NIL) return 0;
  if(T[i].left != NIL) x = get_height(T[i].left) + 1;
  if(T[i].right != NIL) y = get_height(T[i].right) + 1;
  if(x > y) return x;
  else return y;
}

int get_sib(int i){
  if(T[i].parent == NIL) return NIL;
  if((T[T[i].parent].right != NIL) && (T[T[i].parent].right != i))  return T[T[i].parent].right;
  else if((T[T[i].parent].left != NIL) && (T[T[i].parent].left != i)) return T[T[i].parent].left;
  else return -1;
}

void print(void){
  int i;
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].parent,get_sib(i),calc_deg(i),Calc_depth(i),get_height(i));
    type_pri(i);
    printf("\n");
  }
}

int main()
{
  int i,id,n1,n2;
  scanf("%d",&n);
  for(i = 0; i < n;i++){
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }
  for(i = 0; i < n;i++){
    scanf("%d%d%d",&id,&n1,&n2);
    T[id].left = n1;
    T[id].right = n2;
    if(n1 != NIL && n2 != NIL){
      T[n1].parent = id;
      T[n2].parent = id;
    }
    else if(n1 == NIL && n2 != NIL) T[n2].parent = id;
    else if(n1 != NIL && n2 == NIL) T[n1].parent = id;
  }
  print();
  return 0;    
}
