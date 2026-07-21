#include<stdio.h>

#define N 100001
#define NIL -1

struct Node{
  int p,d,left,right;
};

struct Node T[N];

int depth(int );
void print(int );
void print_node(int );
void print_element(int );

int count,n;

main() {
  int i,j;
  int id=0;
  int d=0;
  int n=0;
  int c=0;
  int a=0;

  scanf("%d",&n);
  if(n < 1 || N < n) return 0;

  for(i=0;i < n;i++){
    T[i].p = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }

  for(i=0;i < n;i++){
    scanf("%d %d",&id,&d);
    for(j=0;j < d;j++){
      scanf("%d",&c);

      if(j == 0) T[id].left = c;
      else T[a].right = c;

      T[c].p = id;
      a = c;
    }
  }
  
  for(i=0;i < n;i++){
    count = 0;
    T[i].d = depth(T[i].p);
  }
  
 for(i=0;i < n;i++){
   print(i);
 }

 return 0;
}


int depth(int d){

  if(d == NIL){
    return count;
  }

  else{
    count++;
    return depth(T[d].p);
  }
}

void print(int i){

  printf("node %d: ",i);
  printf("parent = %d, ",T[i].p);
  printf("depth = %d,",T[i].d);

  print_node(i);

  printf("[");

  if(T[i].left != NIL){
    printf("%d",T[i].left);
    print_element(T[i].left);
  }

  printf("]");
  printf("\n");
}

void print_node(int i){

  if(T[i].p == NIL) printf(" root, ");
  else if(T[i].left == NIL) printf(" leaf, ");
  else printf(" internal node, ");

}

void print_element(int i){

   if(T[i].right != NIL){
    printf(", %d",T[i].right);
    print_element(T[i].right);
  }
}
