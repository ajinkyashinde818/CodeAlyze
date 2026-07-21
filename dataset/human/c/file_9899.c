#include <stdio.h>
#define NIL -1

int depth(int);
void print();

struct Node{
  int parent;
  int left;
  int right;
};

struct Node T[1000001];
int num=0;
int i,j,n,id,c,r,l;
int ids[100001];
int k;

int main(){
 
  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent=NIL;
    T[i].left=NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    ids[id]=k;
    for(j=0;j<k;j++){
      scanf("%d",&c);
      T[c].parent=id;
      if(j==0) T[id].left=c;
      else if(j>0){
	T[l].right=c;
      }
      l=c;
    }
  }

  for(i=0;i<n;i++){
    num=0;
    printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,depth(i));
    if(T[i].parent==NIL){
      printf("root, [");
      print();
      printf("]\n");
    }
    else if( T[i].left>=0){
      printf("internal node, [");
      print();
      printf("]\n");
    }
    else if(T[i].left==NIL) printf("leaf, []\n");
  }

  return 0;
}

int depth(int t){
  int p=T[t].parent;
  if(p==NIL) return num;
  num++;
  depth(p);
}

void print(){
  for(j=0;j<ids[i];j++){
    if(j==0) {
      printf("%d",T[i].left);
      l=T[i].left;
    }
    else if(j<ids[i]-1){
      printf(", %d",T[l].right);
      l=T[l].right;
    }
    else if(j<=ids[i]-1){
      printf(", %d",T[l].right);
    }
  }
  
  
}
