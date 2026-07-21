#include <stdio.h>
#define M 100000
#define NUL -1

struct node{int oya,L,R; };
struct node s[M];

int r[M],o[M];

void deep(int x,int y){
  if(x==NUL) return;
  r[x]=y;
  deep(s[x].L,y+1);
  deep(s[x].R,y+1);
}

int hy(int x){
  int a=0,b=0;
  if(s[x].L!=NUL) a=hy(s[x].L)+1;
  if(s[x].R!=NUL) b=hy(s[x].R)+1;
  if(a>b) return o[x]=a;
  else return o[x]=b;
}

int sib(int x){
  if(s[x].oya==NUL) return NUL;
  if(s[s[x].oya].L!=x && s[s[x].oya].L!=NUL) return s[s[x].oya].L;
  if(s[s[x].oya].R!=x && s[s[x].oya].R!=NUL) return s[s[x].oya].R;
  return NUL;
}

int main()
{
  int x,i,pa,o1,l1,r1,deg;

  scanf("%d",&pa);

  for(i=0;i<pa;i++) s[i].oya=NUL;

  for(i=0;i<pa;i++){
    scanf("%d%d%d",&o1,&l1,&r1);
    s[o1].L=l1;
    s[o1].R=r1;
    if(l1!=NUL) s[l1].oya=o1;
    if(r1!=NUL) s[r1].oya=o1;
  }

  for(i=0;i<pa;i++) if(s[i].oya==NUL) x=i;

  deep(x,0);
  hy(x);

  for(i=0;i<pa;i++){
    printf("node %d: parent = %d, sibling = %d, ",i,s[i].oya,sib(i));

    deg=0;
    if(s[i].L!=NUL) deg++;
    if(s[i].R!=NUL) deg++;

    printf("degree = %d, depth = %d, height = %d, ",deg,r[i],o[i]);

    if(s[i].oya==NUL) printf("root");
    else if(s[i].L==NUL && s[i].R==NUL) printf("leaf");
    else printf("internal node");
    printf("\n");
  }

  return 0;
}
