#include<stdio.h>
#define N 25

typedef struct{
  int parent;
  int sibling;
  int degree;
  int left;
  int right;
  int depth;
  int height;
}node;

int height(int);
node T[N];

int main(){
  int n, i, j;
  int id, c1, c2, p;

  scanf("%d\n",&n);
  for(i = 0 ; i < n ; i++){
    T[i].parent = -1;
    T[i].sibling = -1;
    T[i].degree = 0;
    T[i].left = -1;
    T[i].right = -1;
    T[i].depth = 0;
    T[i].height = 0;
  }

  for(i = 0 ; i < n ; i++){
    scanf("%d%d%d", &id, &c1, &c2);
    T[id].left = c1;
      T[c1].parent = id;
      T[c1].sibling = c2;
      T[id].right = c2;
      T[c2].parent = id;
      T[c2].sibling = c1;
    if(c1 != -1 && c2 != -1){
      T[id].degree = 2;
    }
    else if(c1 != -1 || c2 != -1){
      T[id].degree = 1;
    }
  }
  
  for(i = 0 ; i < n ; i++){
    j = i;
    while(1){
      p = T[j].parent;
      if(p == -1) break;
      j = p;
      T[i].depth++;
    }
  }
    
  for(i=0 ; i<n ; i++){
    T[i].height = height(i);
  }

  for(i = 0 ; i < n ; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,",i, T[i].parent, T[i].sibling, T[i].degree, T[i].depth, T[i].height);
    if(T[i].parent == -1){
      printf(" root\n");
    }
    else if(T[i].height == 0){
      printf(" leaf\n");
    }
    else{
      printf(" internal node\n");
    }
  }
  return 0;
}

int height(int x)
{
  int h1=0,h2=0;
 
  if(T[x].left == -1 && T[x].right == -1){
    return 0;
  }
  else {
    if(T[x].left == -1){
      h2 += (height(T[x].right)+1);
    }
    else if(T[x].right == -1){
      h1 += (height(T[x].left)+1);
    }
    else{
      h1 += (height(T[x].left)+1);
      h2 += (height(T[x].right)+1);
    }
    if( h1 > h2 ) return h1;
    else return h2;
  }
}
