#include<stdio.h>
#define MAX 100005
#define NIL -1
struct Node_struct{int p, l, r, s;};
/*p: 親(parent), l: 一番左の子(left child), r:右の兄弟(right sibling)*/
//s: 兄弟(sibling)
typedef struct Node_struct Node;
Node T[MAX];
int D[MAX];
int DEG[MAX];
int H[MAX];

void print(int u){
  int i, c;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p, T[u].s, DEG[u], D[u], H[u] );

  if(D[u] == 0   /*ここを埋める (fill this blank)*/) printf("root");
  else if( H[u] == 0 /*ここを埋める(fill this blank)*/) printf("leaf");
  else printf("internal node");
  /*  
  printf("[");
  for (i=0, c = T[u].l; c != NIL; i++, c = T[c].r){
    if(i) printf(", ");
    printf("%d", c);
  }
  printf("]\n");
  */
   printf("\n");
}

void calcDepth(int u, int p){
  D[u] = p;
  if( T[u].r != NIL  /*ここを埋める*/) calcDepth( T[u].r, p+1    /*ここを埋める*/);
  if( T[u].l != NIL  /*ここを埋める*/) calcDepth( T[u].l , p+1 /*ここを埋める*/);
}

void calcDegree(int u){
  int tmp=0;
  if(T[u].r != NIL){
    DEG[u]+=1;
    calcDegree(T[u].r);
  }
 if(T[u].l != NIL){
    DEG[u]+=1;
    calcDegree(T[u].l);
  }



}


int calcHeight(int u){

  int left=0,right=0;

  if(T[u].l == NIL && T[u].r == NIL){
     H[u] = 0 ;
    return 0;
  }
  if( T[u].r != NIL) right = calcHeight(T[u].r)+1;
  if(T[u].l != NIL) left = calcHeight(T[u].l)+1;
		    
  if(left > right)  H[u] = left;
  else H[u] = right;

  return H[u];
}



int main(){
  int i, j, k;
  int n;
  int id, sib, child;
  int root = NIL;
  scanf("%d", &n);
  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;
  
  for(i=0; i<n; i++){
    scanf("%d", &id);

    for(j = 0, sib = NIL; j<2; j++){ //子を入力する (input children)//2回まわす
      scanf("%d", &child);
      T[child].p = id;
      if(j == 0){
	T[id].l = child; //idの一番左の子 (the most left child of id)
	
      }else{
	T[id].r = child; //左の兄弟に繋げる (connect to left sibling)
        //T[child].s = T[id].l;//兄弟の情報を伝える
	T[T[id].r].s = T[id].l;
	T[T[id].l].s = T[id].r;
	
      }
      sib = child;//次の子供の左の兄弟 (the left sibling of the next child)
    }
    //    T[T[child].s].s = T[T[child].s].r;//兄弟の情報を伝える
	
  }

  //根を求める (find the root)
  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }
  T[root].s = NIL; //ルートの兄弟を初期化
  //それぞれのノードの深さを求める (find depth of each node)
  calcDepth(root, 0);

  //for(i=0; i<n; i++){
    calcDegree(root);
    //}
  //for(i=0; i<n; i++){
    calcHeight(root);
    //  }
    
  //出力 (output)
  for(i=0; i<n; i++) print(i);
  
  return 0;
}
