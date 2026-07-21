#include <stdio.h>
#define MAXN 100
#define NIL -1
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

struct Node{
  int p, l, r;
};

struct Node binTree[MAXN];

int getDepth(int u) // book p190
{
  int d = 0;
  while (binTree[u].p != NIL){
    u = binTree[u].p;
    d++;
  }
  return d;
}

int getHeight(int u)// book p195
{
  int h1 = 0;
  int h2 = 0;
  if (binTree[u].l!= NIL)
    h1 = getHeight(binTree[u].l) +1;
  if (binTree[u].r!= NIL)
    h2 = getHeight(binTree[u].r) +1;
  
  return MAX(h1,h2);
}

int getSibling(int u)// return l or r  book p196
{
  if ( binTree[u].p == NIL ) return NIL;
  if ( binTree[binTree[u].p].l != u && binTree[binTree[u].p].l != NIL ) return binTree[binTree[u].p].l;
  if ( binTree[binTree[u].p].r != u && binTree[binTree[u].p].r != NIL ) return binTree[binTree[u].p].r;
  return NIL;
}

void print(int N){
  int i, d,s,degree,h;
  for ( i = 0; i <N; i++ ){
    d = getDepth(i);
    s = getSibling(i);
    degree=0;
    if (binTree[i].l !=NIL) degree++;
    if (binTree[i].r !=NIL) degree++;
    h = getHeight(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,binTree[i].p, s, degree, d, h);// PE error, parent= to parent =

    if ( binTree[i].p == NIL ){
      printf("root\n");
    } else if ( binTree[i].l == NIL && binTree[i].r == NIL ){
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
}

int main(void)
{
  int n,i,v,l,r;
  scanf("%d", &n);
  
  // init binbinTreeree
  for ( i = 0; i < n; i++ ) {
    binTree[i].p=NIL;
    binTree[i].l=NIL;
    binTree[i].r=NIL;
  }

  //input v,l,r for current node
  for ( i = 0; i < n; i++ ){
    scanf("%d %d %d", &v, &l, &r);
    binTree[v].l=l;
    binTree[v].r=r;
    if (l != NIL) binTree[l].p=v;
    if (r != NIL) binTree[r].p=v;
  }
  print(n);
  
  return 0;
}
