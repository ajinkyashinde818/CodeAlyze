#include<stdio.h>
#define max 25

typedef struct{
  int parent;
  int id;
  int left;
  int right;
  int sibling;
  int degree;
  int depth;
  int height;
}node;

node T[max];
int n;

int getSibling(int );
int getDegree(int );
int getDepth(int );
int getHeight(int );
void Judge(int );


int main(){
  int id,l,r;
  int i,S,D1,D2,H;
  
  for(i=0 ; i<max ; i++){
    T[i].parent = -1;
    T[i].left = -1;
    T[i].right = -1;
  }
  
  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%d",&id);
    T[id].id = id;
    scanf("%d%d",&l,&r);
    if(l != -1){
      T[id].left = l;
      T[l].parent = id;
    }
    if(r != -1){
      T[id].right = r;
      T[r].parent = id;
    }
  }

  for(i=0 ; i<n ; i++){
    T[i].sibling = getSibling(i);
    T[i].degree = getDegree(i);
    T[i].depth = getDepth(i);
    T[i].height = getHeight(i);
  }

  for(i=0 ; i<n ; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,",
	   T[i].id, T[i].parent, T[i].sibling, T[i].degree, T[i].depth, T[i].height);
    Judge(i);
  }

  return 0;
}

int getSibling(int i){
  int k;
  for(k=0 ; k<n ; k++){
    if(k == i) continue;
    else{
      if(T[i].parent == T[k].parent){
	return T[k].id;
	break;
      }
    }
  }
  return -1;
}

int getDegree(int i){
  if(T[i].left == -1 && T[i].right == -1) return 0;
  else if(T[i].left != -1 && T[i].right == -1) return 1;
  else if(T[i].left == -1 && T[i].right != -1) return 1;
  else return 2;
}

int getDepth(int i){
  int count = 0;

  while(1){
    if(T[i].parent == -1) break;
    i=T[i].parent;
    count++;
  }
  return count;
}

int getHeight(int n){
  int right=0,left=0;
  if(T[n].right == -1 && T[n].left == -1) return 0;
 
  if(T[n].right != -1) right = getHeight(T[n].right)+1;
  if(T[n].left != -1) left = getHeight(T[n].left)+1;
 
  if(left > right) return left;
  else return right;
}

void Judge(int i){
  int t;

  if(T[i].parent == -1) printf(" root\n");
  else if(T[i].left == -1 && T[i].right == -1) printf(" leaf\n");
  else printf(" internal node\n");
}
