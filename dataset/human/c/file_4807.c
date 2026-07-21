#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define NIL -1

typedef struct t{
  int id;
  int parent;
  int degree;
  int depth;
  int child[2];
  int sibling;
  int height;
}Tree;

void depthcalculation(int, int);
void heightcalculation(int);

Tree T[N];
int maxdepth = 0;

int main(){
  int treenum, i, id, j;
  
  scanf("%d", &treenum);
  
  //preparation
  for(i = 0; i < treenum; i++){
    T[i].parent = NIL;
    T[i].depth = 0;
    T[i].sibling = -1;
    T[i].height = 0;
    T[i].degree = 0;
  }
  
  //input
  for(i = 0; i < treenum; i++){
    scanf("%d", &id);
    T[id].id = id;
    
    for(j = 0; j < 2; j++){
      
      scanf("%d", &T[id].child[j]);
      
      if(T[id].child[j] != NIL){
	T[ T[id].child[j] ].parent = T[id].id;
	T[id].degree++;
      }
      
    }
   
      T[ T[id].child[0] ].sibling = T[id].child[1];
      T[ T[id].child[1] ].sibling = T[id].child[0];
    
  }
  
  //root search
  for(i = 0; i < treenum; i++){
    if(T[i].parent == NIL){
      break;
    }
  }
  
  depthcalculation(i, 0);
  heightcalculation(treenum);
  T[i].height = maxdepth;
  
  //output
  for(i = 0; i < treenum; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, ", T[i].id, T[i].parent, T[i].sibling, T[i].degree);

    printf("depth = %d, height = %d, ",T[i].depth, T[i].height);
    
    if(T[i].parent == -1){
      printf("root\n");
    }
    else if(T[i].degree == 0){
      printf("leaf\n");
    }
    else{
      printf("internal node\n");
    }
  }
  
  return 0;
}

void depthcalculation(int t, int d){
  int i;

  T[t].depth = d;
  
  if(maxdepth < d){
    maxdepth = d;
  }
  
  for(i = 0; i < 2; i++){
    if(T[t].child[i] != NIL){
    depthcalculation(T[t].child[i], d+1);
    }
  }
  
}

void heightcalculation(int treenum){
  int i, h, id;

  for(i = 0; i < treenum; i++){
    if(T[i].degree == 0){
      h = 0;
      id = T[i].id;
      T[i].height = 0;
      
      while(1){
	id = T[id].parent;
	if(id == NIL){
	  break;
	}
	h++;

	if(T[id].height < h){
	  T[id].height = h;
	}
      }
      
    }
  }
}
