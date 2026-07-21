#include<stdio.h>
#define N 100000
  int getDep(int);
struct Node{
  int p;
  int left;
  int right;
  int s;
  int h;
    }Node;
  
struct Node T[N];
  
int getDep(int u){
  int d=0;  
  for(;T[u].p != -1; d++) u=T[u].p; 
  return d;
}
void setHei(int n){
  int d,i,j;
  for(i = 0;i < n;i++){
     
    if(T[i].right == -1 && T[i].left == -1){
      T[i].h == 0;
      for(j = i,d = 1;j != -1; d++){
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
   
 for(i = 0;i < n;i++) {
     
    T[i].p = -1;
    T[i].left = -1;
    T[i].right = -1;
    T[i].s = -1;
  }
    
 for(i = 0;i < n;i++){
   scanf("%d %d %d",&v,&d,&c);
   if( d!= -1 && c == -1){
     T[v].left = d;
     T[d].p = v;
   }
   if(c != -1 && d == -1){
    T[v].right = c;
    T[c].p = v;
   }
   if(d != -1 && c != -1){
     T[v].left = d;
     T[d].p = v;
     T[v].right = c;
     T[c].p = v;
     T[d].s = c;
     T[c].s = d;
   }
 }  
     
 for(i = 0;i < n;i++){
    
   printf("node %d: parent = %d, sibling = %d, ",i,T[i].p,T[i].s);
   if(T[i].right == -1 && T[i].left == -1) printf("degree = 0, ");
     
else if(T[i].right == -1 || T[i].left == -1) printf("degree = 1, ");
    
   else printf("degree = 2, ");
   setHei(n);
   printf("depth = %d, height = %d,",getDep(i),T[i].h);
  
   if(T[i].p == -1) printf(" root\n");
  
   else if(T[i].left == -1 && T[i].right == -1) printf(" leaf\n");
  
   else printf(" internal node\n");
 }
 return 0;
}
