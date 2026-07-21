#include<stdio.h>

#define N 100001
#define NIL -1


struct Node{ 
  int p,left,right,deg,dep,s,h;
};

struct Node T[N];

int depth(int );
int height(int, int);
void print(int );
void print_node(int );

int count,n;

main(){
  int i,j;
  int id=0;
  int c=0;
  int left=0,right=0;

  n =0;
  
  scanf("%d",&n);
  if(n < 1 || N < n) return 0;
  
  for (i=0;i < n;i++){
    T[i].left = NIL; 
    T[i].right = NIL;
    T[i].p = NIL;
    T[i].s = NIL;
  }
  
  for (i=0;i < n;i++){
    c=0;
    scanf("%d %d %d",&id,&left,&right);

    T[id].left = left;
    T[id].right = right;

    T[left].p = id;
    T[left].s = right;

    T[right].p = id;
    T[right].s = left;

    if(left == NIL){
      c++;
    } 
    if(right == NIL){
      c++;
    }

    if(c == 0){
      T[id].deg = 2;
    }
    else if(c == 1){
      T[id].deg = 1;
    }
    else{
      T[id].deg = 0;
    }
  }
 
  for(i=0;i < n; i++){
    count = 0;

    T[i].dep  = depth(T[i].p);
    T[i].h = height(i,0);
  }

  for (i=0;i < n;i++) print(i);

  return 0;
}

int depth(int i){

  if(i == NIL){
    return count;
  }

  else{
    count++;
    return depth(T[i].p);
  }
}

int height(int h, int c){
  int a=0;
  int b=0;
  
  if(T[h].right != NIL){
    a = height(T[h].right, c+1);
  }
  
  if(T[h].left != NIL){
    b = height(T[h].left, c+1);
  } 
  
  if(T[h].left == NIL && T[h].right == NIL){
    return c;
  }
  
  if(a >= b){
    return a;
  }
  return b;  
}

void print(int i){

  printf("node %d:", i);
  printf(" parent = %d,", T[i].p);
  printf(" sibling = %d,", T[i].s);
  printf(" degree = %d,", T[i].deg);
  printf(" depth = %d,", T[i].dep);
  printf(" height = %d,", T[i].h);
  print_node(i);
  printf("\n");
}


void print_node(int i){

  if(T[i].p == NIL){
    printf(" root");
  }
  
  else if(T[i].deg == 0){
    printf(" leaf");
  }

  else{
    printf(" internal node");
  }
}
