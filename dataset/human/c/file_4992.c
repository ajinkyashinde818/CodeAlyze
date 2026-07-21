#include <stdio.h>

#define MAX 100001

typedef struct{
  int parnodnm;
  int sibling;
  int degree;
  int child[2];
  int depth;
  int height;
  int typ;
}Node;

Node T[MAX];

int calcudepth(int u){
  int d = 0;
  while(T[u].parnodnm != -1){
    u = T[u].parnodnm;
    d++;
  }
  return d;
}

int calcuheight(int u){
  int h1 = 0, h2 = 0;
  if(T[u].child[0] != -1)
    h1 = calcuheight(T[u].child[0]) + 1;
  if(T[u].child[1] != -1)
    h2 = calcuheight(T[u].child[1]) + 1;
  
  return h1 > h2 ? h1 : h2;
}

int main(){
  int nm, i, j, nodnm;
  int flag = 0;
  int D[MAX];
  
  scanf("%d", &nm);
  
  for(i = 0; i < nm; i++){
    T[i].parnodnm = -1;
    T[i].sibling = -1;
    T[i].typ = 2;
  }
  for(i = 0; i < nm; i++){
    scanf("%d", &nodnm);
    T[nodnm].degree = 2;
    flag = 0;
    for(j = 0; j <2; j++){
      scanf("%d", &T[nodnm].child[j]);
      if(T[nodnm].child[j] == -1){
	flag++;
	T[nodnm].degree--;
      }
      T[T[nodnm].child[j]].parnodnm = nodnm;
    }
    if(flag == 2) T[nodnm].typ = 1;
    T[T[nodnm].child[0]].sibling = T[nodnm].child[1];
    T[T[nodnm].child[1]].sibling = T[nodnm].child[0];
  }
  
  for(i = 0; i < nm; i++)
    if(T[i].parnodnm == -1) T[i].typ = 0;
  
  for(i = 0; i < nm; i++) T[i].depth = calcudepth(i);
  
  for(i = 0; i < nm; i++){
    if(T[i].typ == 0)
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n", i, T[i].parnodnm, T[i].sibling, T[i].degree, T[i].depth, calcuheight(i));
    else if(T[i].typ == 1)
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n", i, T[i].parnodnm, T[i].sibling, T[i].degree, T[i].depth, calcuheight(i));
    else if(T[i].typ == 2)
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n", i, T[i].parnodnm, T[i].sibling, T[i].degree, T[i].depth, calcuheight(i)); 
  }
  
  return 0;
}
