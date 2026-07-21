#include<stdio.h>
#define MAX 100005
#define NIL -1

/*
p: parent
l: left-child
r: right sibling
*/
struct Node{ int p, l, r,d;};
struct Node T[MAX]; 
int depth[MAX];




void print(int u){
 /*
  */
 printf("node %d: parent = %d, depth = %d, ",u,T[u].p,T[u].d);
 if(T[u].p==-1){
 	printf("root, [");
 }else if(T[u].l==NIL){
 	printf("leaf, [");
 }else{
 	printf("internal node, [");
 }
 int p=T[u].l;

 while(p!=NIL){
      if(p==T[u].l)printf("%d",p);
      else printf(", %d",p);
     p=T[p].r;
 }
  printf("]\n");
}

void calc_depth(int deep,int p){
	T[p].d=deep;
	if(T[p].l==NIL)return;
	for(p=T[p].l;p!=NIL;p=T[p].r){
		calc_depth(deep+1,p);
	}
} 

int main(){
 int i, j, d, v, c, l,n;

 scanf("%d", &n);

 for ( i = 0; i < n; i++ ) {
   T[i].p = T[i].l = T[i].r = NIL;
 }

  for ( i = 0; i < n; i++ ){
   scanf("%d %d", &v, &d);
    int old=0;
    for ( j = 0; j < d; j++ ){
      scanf("%d", &c);
	T[c].p=v;
 	if(j==0){
		T[v].l=c;
	}else{
		T[old].r=c;
	}
	old=c;
   }
 }
   int p;
  for(int i=0;i<n;i++)if(T[i].p==-1)p=i;
  calc_depth(0,p); 
  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
