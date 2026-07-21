#include <stdio.h>

#define N 100001

typedef struct{
  int parent;
  int left;
  int right;
  int sibling;
}Node;

Node T[N];
int depth[N];

int heightcheck(Node T[], int i){
  int height = 0;
  int left, right;
  if(T[i].left == -1 && T[i].right == -1) return height;
  else if(i == -1) return height;

  left = heightcheck(T,T[i].left);
  right = heightcheck(T,T[i].right);
  if(left > right) return left + 1;
  else return right + 1;
}
int main(){
  int n, i, j, buf;
  int id, degree;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    T[i].parent = -1;
    T[i].left = N;
    T[i].right = N;
    T[i].sibling = -1;
    depth[i] = 0;
  }

  for(i = 0; i < n; i++){
    scanf("%d", &id);
    scanf("%d%d", &T[id].left, &T[id].right);

    if(T[id].left != -1){
      T[T[id].left].parent = id;
      T[T[id].left].sibling = T[id].right;
    }

    if(T[id].right != -1){
      T[T[id].right].parent = id;
      T[T[id].right].sibling = T[id].left;
    }
  }

  for(i = 0; i < n; i++){
     buf = T[i].parent;
      while(1){
	if(buf == -1) break;
	else {
	  buf = T[buf].parent;
	  depth[i]++;
	}
      }

      printf("node %d: parent = %d, sibling = %d,", i, T[i].parent, T[i].sibling);

      if(T[i].left != -1 && T[i].right != -1){
	printf(" degree = 2, depth = %d, height = %d,", depth[i], heightcheck(T,i));
	if(T[i].parent == -1)printf(" root\n");
	else printf(" internal node\n");
      }
      else if(T[i].left != -1 || T[i].right != -1){ 
	printf(" degree = 1, depth = %d, height = %d,", depth[i], heightcheck(T,i));
	if(T[i].parent == -1)printf(" root\n");
	else printf(" internal node\n");
      }
      else{
	printf(" degree = 0, depth = %d, height = %d,", depth[i], heightcheck(T,i));
	if(T[i].parent == -1)printf(" root\n");
	else printf(" leaf\n");
      }
  }
  return 0;
}
