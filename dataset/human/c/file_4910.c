#include <stdio.h>
#define N 25
typedef struct{
    int p,l,r;
    int sib,deg,dep,hei;
}Node;
Node T[N];

int setheight(int);

int main(){
    int n,i;
      int id,left,right;
      scanf("%d",&n);
      for(i=0; i<n; i++) {
          T[i].p = -1;
          T[i].sib = -1;
      }
      for(i=0; i<n; i++){
          scanf("%d",&id);
          scanf("%d%d",&left,&right);
          T[id].l = left;
          T[id].r = right;
          T[left].p = id;
          T[right].p = id;
          T[left].sib = right;
          T[right].sib = left;
      }
      for(id=0; id<n; id++){
          printf("node %d: parent = %d, sibling = %d, ",id,T[id].p,T[id].sib);
          T[id].deg = 0;
          if(T[id].l != -1) T[id].deg++;
          if(T[id].r != -1) T[id].deg++;
          printf("degree = %d, ",T[id].deg);
          T[id].dep = 0;
          i = id;
          while(T[i].p != -1){
              T[id].dep++;
              i = T[i].p;
          }
          printf("depth = %d, ",T[id].dep);
          T[id].hei = 0;
          T[id].hei = setheight(id);
          printf("height = %d, ",T[id].hei);
          if(T[id].p == -1) printf("root\n");
          else if(T[id].deg == 0) printf("leaf\n");
          else printf("internal node\n");          
      }
      return 0;
}

int setheight(int u){
    int h1=0,h2=0;
    if(T[u].l != -1) h1 = setheight(T[u].l) + 1;
    if(T[u].r != -1) h2 = setheight(T[u].r) + 1;
    
    if(h1<h2) return h2;
    else return h1;
}
