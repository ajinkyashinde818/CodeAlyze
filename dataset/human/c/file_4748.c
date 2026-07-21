#include <stdio.h>
#define NIL -1
#define N 100000

int getDepth(int);

struct Node{
  int p;
  int l;
  int r;
  int s;
  int h;
}Node;

struct Node Three[N];

int getDepth(int u){
  int d = 0;

  for(; Three[u].p != NIL; d++){
    u = Three[u].p;
  }

    return d;
  
}

void setHeight(int n){
  int d,i,j;

  for(i = 0; i < n; i++){

    if(Three[i].r == NIL && Three[i].l == NIL){
      Three[i].h = 0;

      for(j = i,d = 1; j != NIL; d++){
	j = Three[j].p;

	if(Three[j].h < d) Three[j].h = d;
      }
    }
  }
}

int main(){

  int i, j;
  int n = 0;
  int v = 0;
  int d = 0;
  int c = 0;
  int l = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++){

    Three[i].p = NIL;
    Three[i].l = NIL;
    Three[i].r = NIL;
    Three[i].s = NIL;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d%d",&v,&d,&c);

    if(d != NIL && c == NIL){
      Three[v].l = d;
      Three[d].p = v;
    }

    if(c != NIL && d == NIL){
      Three[v].r = c;
      Three[c].p = v;
    }

    if(d != NIL && c != NIL){
      Three[v].l = d;
      Three[d].p = v;
      Three[v].r = c; 
      Three[c].p = v;
      Three[d].s = c;
      Three[c].s = d;
    }
  }
  
  for(i = 0; i < n; i++){

    printf("node %d: parent = %d, sibling = %d, ",i,Three[i].p,Three[i].s);
    if(Three[i].r == NIL && Three[i].l == NIL){
      printf("degree = 0, ");
    }
    else if(Three[i].r == NIL || Three[i].l == NIL){
      printf("degree = 1, ");
    }
    else{
      printf("degree = 2, ");
    }

    setHeight(n);

    printf("depth = %d, height = %d,",getDepth(i),Three[i].h);

    if(Three[i].p == NIL){
      printf(" root\n");
    }
    else if(Three[i].l == NIL && Three[i].r == NIL){
      printf(" leaf\n");
    }
    else{
      printf(" internal node\n");
    }
  }

  return 0;
}
