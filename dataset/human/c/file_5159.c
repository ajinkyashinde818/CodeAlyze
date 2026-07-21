#include <stdio.h>
#define N 100005
#define NIL -1
 
typedef struct{
  int p,s,deg,def,h,l,r;
}Node;
Node T[N];
int depth(int id);
int height(int id);
int max(int a, int b);
int main(void){
  int n,i,j,k,z;
  int id,tmp,max,num;
 
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    T[i].p = T[i].s = T[i].deg = T[i].def = T[i].h =NIL;
  }
  for(i = 0; i < n; i++){
    scanf("%d %d %d",&z, &id, &k);
    T[id].p = T[k].p = z;
    T[k].s = id; T[id].s = k;
    if(id==NIL && k==NIL) 
      T[z].deg = 0;
    else if(id!=NIL && k!=NIL) 
      T[z].deg = 2;
    else 
      T[z].deg = 1;
    T[z].l = id; T[z].r = k;
  }
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,T[i].p);
    printf("sibling = %d, ",T[i].s);
    printf("degree = %d, ",T[i].deg);
    printf("depth = %d, ",depth(i));
    printf("height = %d, ",height(i));
    if(T[i].p==-1) T[i].deg=-1;
    switch(T[i].deg){
      case -1: printf("root");          break;
      case  0: printf("leaf");          break;
      case  1: printf("internal node"); break;
      case  2: printf("internal node"); break;
    }
    printf("\n");
  }
	return 0;
}

int depth(int id){
  int tmp;
  tmp=id;
  for( ; ; ){
    if(T[tmp].p!=NIL)
      T[id].def += 1;
    else break;
    tmp=T[tmp].p;
  }    
  return T[id].def+1; 
}
int height(int id){
    if(T[id].h!=-1)
      return T[id].h;
    if(T[id].l == -1 && T[id].r == -1)
      T[id].h = 0;
    else if(T[id].l == -1)
      T[id].h = height(T[id].r) + 1;
    else if(T[id].r == -1)
      T[id].h = height(T[id].l) + 1;
    else
      T[id].h = max( height(T[id].l), height(T[id].r) ) + 1;
    return T[id].h;
}
int max(int a, int b){
    if(a>b) return a;
    else return b;
}
