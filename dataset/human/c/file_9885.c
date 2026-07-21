#include<stdio.h>

#define MAX 100000
#define NILL -1

struct node{
  int p;
  int l;
  int r;
};

struct node a[MAX];
int n;
int D[MAX];// Dは深さを求めるために接点を格納しておく配列

  int depth(int,int);
  void print(int);


int main(){
  int i,j;//カウンタ変数
  int d,v;//dはidvのd行目を示し、vは1〜n-1個あるidのこと
  int c;//idのv行目の内容を表す変数
  int l,r;//leftとrightを表すための適当な変数

  scanf("%d",&n);//nは節点ののこと

  for(i=0; i<n; i++){
    a[i].p=a[i].l=a[i].r=NILL;

  }

  for(i=0; i<n; i++){
    scanf("%d%d",&v,&d);

    for(j=0; j<d; j++){
      scanf("%d",&c);

      if(j==0){
	a[v].l=c;//dの0番目の値を読み込んでいるときleftに値をいれる
      }
      else{
	a[l].r=c;//dの1番目以降を読み込んでいるときright（前の値+1）にいれる
      }

      l=c;
      a[c].p=v;
    }
  }

  for(i=0; i<n; i++){
    if(a[i].p==NILL){//親がいないとき
      r=i;
    }
  }

  depth(r,0);

  for(i=0; i<n; i++){
    print(i);
  }

  return 0;
}


int depth(int u,int p){
  D[u]=p;

  if(a[u].r!=NILL)
    depth(a[u].r,p);
  if(a[u].l!=NILL)
    depth(a[u].l,p+1);
      }

void print(int u){
  int i,c;

  printf("node %d: ",u);
  printf("parent = %d, ",a[u].p);
  printf("depth = %d, ",D[u]);

  if(a[u].p==NILL)
    printf("root, ");
  else if(a[u].l==NILL)
    printf("leaf, ");
  else
    printf("internal node, ");

  printf("[");

  for(i=0,c=a[u].l; c!=NILL; i++, c=a[c].r){
    if(i) printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}
