#include<stdio.h>
#define  NIL -1
#define N 100000

int getDepth(int);


struct Node{
  int p;
  int l;
  int r;
  int s;
  int h;
  
}Node;

 struct Node T[N];

int getDepth(int u){
  int d=0;
   
  
 for(;T[u].p != NIL; d++) u=T[u].p;
  
  return d;
}
void setHeight(int n){
  int d,i,j;
  for(i=0;i<n;i++){
   
    if(T[i].r == NIL && T[i].l == NIL){
      T[i].h == 0;
      for(j = i,d = 1;j != NIL; d++){
	j = T[j].p;
	if(T[j].h < d) T[j].h = d;
	
      }
    }
  }
 
}

int main(){
  int i;
  int j;
  int n = 0;
  int v  =0;
  int d = 0;
  int c = 0;
  int l = 0;
  scanf("%d",&n);
 
 for(i=0;i<n;i++) {
   
    T[i].p=NIL;
    T[i].l=NIL;
    T[i].r=NIL;
    T[i].s=NIL;
  }
  
 for(i=0;i<n;i++){
   scanf("%d %d %d",&v,&d,&c);
   if( d!= NIL && c ==NIL){
     T[v].l = d;
     T[d].p = v;
   }
   if(c != NIL && d == NIL){
    T[v].r = c; 
    T[c].p = v;
   }
   if(d != NIL && c != NIL){
     T[v].l = d;
     T[d].p = v;
     T[v].r = c; 
     T[c].p = v;
     T[d].s = c;
     T[c].s = d;
   }
 }
 
 
 
   
 for(i=0;i<n;i++){
  
   printf("node %d: parent = %d, sibling = %d, ",i,T[i].p,T[i].s);
   if(T[i].r == NIL && T[i].l == NIL) printf("degree = 0, ");
   
else if(T[i].r == NIL || T[i].l == NIL) printf("degree = 1, ");
  
   else printf("degree = 2, ");
   setHeight(n);
   printf("depth = %d, height = %d,",getDepth(i),T[i].h);

   if(T[i].p == NIL) printf(" root\n");

   else if(T[i].l == NIL && T[i].r == NIL) printf(" leaf\n");

   else printf(" internal node\n");
   
  
 }
return 0;
}
