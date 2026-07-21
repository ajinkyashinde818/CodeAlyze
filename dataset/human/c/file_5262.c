#include <stdio.h>
#define MAX 100005
#define NIL -1
struct Node {
    int p;
    int left;
    int right;
};

struct Node Tree[MAX];
int N,D[MAX],H[MAX];

void findDepth(int,int);
int findHeight(int);
int findSibling(int);
void Print(int);

int main(){
  int v, left, right, root = 0;
  scanf("%d",&N);
  for(int i=0;i<N;i++) Tree[i].p = NIL;
  for(int i=0;i<N;i++) {
    scanf("%d %d %d",&v,&left,&right);
    Tree[v].left  = left; Tree[v].right = right;
    if(left != NIL) Tree[left].p = v; if(right != NIL) Tree[right].p = v;
  }
  
  for(int i=0; i<N; i++)if(Tree[i].p == NIL) root = i;
  
  findDepth(root,0);
  findHeight(root);
  
  for(int i=0;i<N;i++) Print(i);
  
  return 0;
}

void findDepth(int value,int d) {
  if(value == NIL) return;
  D[value] = d;
  findDepth(Tree[value].left, d+1);
  findDepth(Tree[value].right,d+1);
}

void Print(int i){  /*mainでのprintを関数化してみた*/
    int degree = 0;
    printf("node %d: parent = %d, sibling = %d, ", i,Tree[i].p,findSibling(i));
    if(Tree[i].left  != NIL) degree++;
    if(Tree[i].right != NIL) degree++;
    printf("degree = %d, depth = %d, height = %d, ",degree,D[i],H[i]);

    if ( Tree[i].p == NIL ) printf("root\n");
    else if (Tree[i].left == NIL && Tree[i].right == NIL ) printf("leaf\n"); /*A.cの条件式に&&〜を加えた*/
    else printf("internal node\n");
}

int findHeight(int r){
    int height1,height2;
    height1 = height2 = 0;

    if(Tree[r].left != NIL)height1 = findHeight(Tree[r].left) + 1;
    if(Tree[r].right != NIL)height2 = findHeight(Tree[r].right) + 1;

    return H[r] = (height1 > height2 ? height1 : height2);
}

int findSibling(int s) {
  if( Tree[s].p == NIL ) return NIL;
  if(Tree[Tree[s].p].left != s && Tree[Tree[s].p].left != NIL )return Tree[Tree[s].p].left;
  if(Tree[Tree[s].p].right != s && Tree[Tree[s].p].right != NIL )return Tree[Tree[s].p].right;
  
  return NIL;
}
