#include <stdio.h>
#define max 30
#define nil -1

typedef struct{
  int parent;
  int lleaf;
  int leaf;
  int next;
  int sibling;
}node;

node t[max];
int n;

int rmax(int l, int r){
  if(l < r) return r;
  else return l;
}

int deg(int id){
  int deg = 0;
  if(t[id].lleaf != nil) deg++;
  if(t[id].leaf != nil) deg++;
  return deg;
}

int dep(int id){
  int depth = 0;
  if(t[id].parent != nil){
    depth = dep(t[id].parent);
    return depth+1;
  }
  else return 0;
}

int hei(int id){
  return rmax(lhei(id), rhei(id));
} 

int lhei(int id){
  int height = 0;

  if(t[id].lleaf == nil) return 0;
  height = hei(t[id].lleaf);
  return height+1;
}

int rhei(int id){
  int height = 0;

  if(t[id].leaf == nil) return 0;
  height = hei(t[id].leaf);
  return height+1;
}



int main(void){
  int i, j, id, left, right, mheight;

  scanf("%d", &n);
  //init
  for(i = 0; i < max; i++)
    t[i].parent = t[i].leaf = t[i].next = t[i].sibling = nil;



  for(i = 0; i < n; i++){
    scanf("%d", &id);
    scanf("%d", &left);
    scanf("%d", &right);
      t[left].parent = id;
      t[left].sibling = right;
      t[left].next = right;
      t[id].lleaf = left;

      t[right].parent = id;
      t[id].leaf = right;
      t[right].sibling = left;
  }

  for(i = 0; i < n; i++){
    printf("node %d: ", i); 
    printf("parent = %d, ", t[i].parent);
    printf("sibling = %d, ", t[i].sibling);
    printf("degree = %d, ", deg(i));
    printf("depth = %d, ", dep(i));
    printf("height = %d, ",hei(i));

  if(t[i].parent == nil)
    printf("root");
  else if(t[i].leaf != nil || t[i].lleaf != nil)
    printf("internal node");
  else
    printf("leaf"); 
  printf("\n");



  }
  return 0;
}
