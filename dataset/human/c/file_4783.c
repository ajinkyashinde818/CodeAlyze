#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{ int p, l, r, dg,d, s, h;};
struct Node T[MAX]; // Tree

int count1 = 0, n;
int getdepth(int);
void  prinr(int);
int getheight(int, int);

int getdepth(int d){

  if(d == NIL){
    return count1;
  }

  else{
    count1++;
    return getdepth(T[d].p);
  }

}

int getheight(int h, int c){

  int a=0, b=0;
  
  if(T[h].r != NIL){
    a = getheight(T[h].r, c+1);
  }
  
  if(T[h].l != NIL){
    b = getheight(T[h].l, c+1);
  } 
  
  if(T[h].l == NIL && T[h].r == NIL){
    return c;
  }
  
  if(a>=b){
    return a;
  }
  return b;
  
}
  

void print(int u){
 
  printf("node %d:", u);
  
  printf(" parent = %d,", T[u].p);
  
  printf(" sibling = %d,", T[u].s);

  printf(" degree = %d,", T[u].dg);

  printf(" depth = %d,", T[u].d);

  printf(" height = %d,", T[u].h);

  prinr(u);

    printf("\n");


}


void prinr(int u){

  if(T[u].p == NIL){
    printf(" root");
  }
  
  else if(T[u].dg == 0){
    printf(" leaf");
  }

  else{
    printf(" internal node");
  }

}

main(){
  int i, j, d, v, c, l, r;

  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = T[i].dg = T[i].s = NIL;
  }

  for ( i = 0; i < n; i++ ){
    c=0;
    scanf("%d %d %d", &v, &l, &r);

    T[v].l = l;
    T[v].r = r;

    T[l].p = v;
    T[l].s = r;

    T[r].p = v;
    T[r].s = l;

    if(l == NIL){
      c++;
    } 
    if(r == NIL){
      c++;
    }

    if(c == 0){
      T[v].dg = 2;
    }
    else if(c == 1){
      T[v].dg = 1;
    }
    else{
      T[v].dg = 0;
    }

  }
 
  for(i=0; i<n; i++){
    count1 = 0;

    T[i].d  = getdepth(T[i].p);
    T[i].h = getheight(i, 0);

  }

  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
