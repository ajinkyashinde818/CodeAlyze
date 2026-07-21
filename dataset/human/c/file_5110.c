#include <stdio.h>
#define N 100000

int preParse(int,int);

struct Node{
  int p,l,r,s,deg,dep,h;
};

struct Node T[N];
int main()
{
  int n,i,j,m,hei,a,b;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    T[i].p=-1;
    T[i].s=-1;
  }
  for(i=0; i<n; i++){
    scanf("%d",&j);
    scanf("%d%d",&T[j].l,&T[j].r);
  }
  
  for(i=0; i<n; i++){
    a=T[i].l;
    b=T[i].r;
    if(a==-1 && b==-1)T[i].deg=0;
    else if(a==-1 || b==-1)T[i].deg=1;
    else T[i].deg=2;
    T[a].p=i;
    T[b].p=i;
    T[a].s=b;
    T[b].s=a;
  }
  
  for(i=0; i<n; i++){ 
    m=T[i].p;
    T[i].dep=0;
    while(1){
      if(m==-1)break;
      else {
	m=T[m].p;
	T[i].dep++;
      }
    }

    hei=preParse(i,0);
    T[i].h = hei-1;

    hei=0;

  }

  for(i=0; i<n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, ",i,T[i].p,T[i].s,T[i].deg);
    printf("depth = %d, height = %d, ",T[i].dep,T[i].h);

    if(T[i].p == -1)printf("root\n");
    else if(T[i].deg == 0)printf("leaf\n");
    else printf("internal node\n");
  }
  
  return 0;
}

preParse(int u, int h){
  int a=0,b=0;
  if(u==-1){
    return h;
  }
  else h++;

  a=preParse(T[u].l,h);
  b=preParse(T[u].r,h);
  if(a>=b)return a;
  else return b;
}
