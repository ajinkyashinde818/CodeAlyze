#include<stdio.h>

#define N 10000
#define NIL -1

void print(int);
void rec1(int, int);
int rec2(int);
int get(int);

struct Node {
  int p;
  int l;
  int r;
};

struct Node T[N];
int x,data[N],dat[N];

int main() {
  int i,x,y,z,w,r;

  scanf("%d",&x);
  for(i = 0; i < x; i++) {
    T[i].p = NIL;
  }

  for(i = 0; i < x; i++) {
    scanf("%d",&y);
    scanf("%d",&z);
    scanf("%d",&w);
   
    T[y].l = z;
    T[y].r = w;
    if(z != NIL) {
      T[z].p = y;
    }
    if(w != NIL) {
      T[w].p = y;
    }
  }
  for(i = 0; i < x; i++) {
    if(T[i].p == NIL) {
      r = i;
    }
  }
  rec1(r,0);
  rec2(r);
  for(i = 0; i < x; i++) {
    print(i);
  }
  
  return 0;
}

void rec1(int a, int b) {
  data[a] = b;
  if(T[a].r != NIL) {
    rec1(T[a].r,b + 1);
  }
  if(T[a].l != NIL) {
    rec1(T[a].l,b + 1);
  }
}

int rec2(int a) {
  int h1 = 0,h2 = 0;
  if(T[a].l != NIL) {
    h1 = rec2(T[a].l) + 1;
  }
  if(T[a].r != NIL) {
    h2 = rec2(T[a].r) + 1;
  }
  return dat[a] = (h1 > h2 ? h1 : h2);
}

int get(int a) {
  if(T[a].p == NIL) {
    return NIL;
  }
  if(T[T[a].p].l != a && T[T[a].p].l != NIL) {
    return T[T[a].p].l;
  }
  if(T[T[a].p].r != a && T[T[a].p].r != NIL) {
    return T[T[a].p].r;
  }
  return NIL;
}
  


void print(int a) {
  int deg = 0;
  printf("node %d: ",a);
  printf("parent = %d, ",T[a].p);
  printf("sibling = %d, ",get(a));

  if(T[a].l != NIL) {
    deg++;
  }
  if(T[a].r != NIL) {
    deg++;
  }
  printf("degree = %d, ",deg);
  printf("depth = %d, ",data[a]);
  printf("height = %d, ",dat[a]);

  if(T[a].p == NIL) {
    printf("root\n");
  }else if(T[a].l == NIL && T[a].r == NIL) {
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }
}
