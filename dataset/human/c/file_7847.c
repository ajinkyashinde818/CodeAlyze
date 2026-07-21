#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char m[1002][1002];
char r[1002][1002];
struct node {
  unsigned x:10;
  unsigned y:10;
  unsigned int l;
  struct node* n;
} *qs,*qe;
typedef struct node st;
void push(int x,int y,int l)
{
  st *p = qe;
  if(qe == NULL){
    qe = (st *)(malloc(sizeof(st)));;
    qs = qe;
  }else{
    p->n = (st *)(malloc(sizeof(st)));
    qe = p->n;
  }
  qe->x = x;
  qe->y = y;
  qe->l = l;
  qe->n = NULL;
  r[y][x] = 1;
}
st *pop()
{
  st *p = qs;
  if(qs == NULL) return NULL;
  qs = qs->n;
  if(qs == NULL) qe = NULL;
  return p;
}
void flush()
{
  st *p = qs;
  while(p != NULL){
    qs = qs->n;
    free(p);
    p = qs;
  }
  qe = NULL;
}
int search(int* xs,int* ys,int d)
{
  st *p;
  int l,i,x,y;
  int xd[] = {-1,1,0,0}, yd[] = {0,0,-1,1};
  memset(r,0,sizeof(r));
  push(*xs,*ys,0);
  while((p = pop()) != NULL){
    for(i=0; i<4; i++) {
      x = (p->x) + xd[i];
      y = (p->y) + yd[i];
      if(m[y][x] == d) {
	*xs = x;
	*ys = y;
	l = (p->l) + 1;
	free(p);
	return l;
      }
      if((m[y][x] != -1) && (r[y][x] == 0))
	push(x, y, (p->l)+1);
    }
    free(p);
  }
}
int main(){
  int h,w,n,i,j,xs,ys,t=0;
  char c[1002];
  memset(m,-1,sizeof(m));
  scanf("%d%d%d\n",&h,&w,&n);
  for(i=1;i<=h;i++){
    scanf("%s",c);
    for(j=1;j<=w;j++){
      switch(c[j-1]){
      case 'S':
	xs = j; ys = i;
      case '.':
	m[i][j] = 0;
	break;
      case 'X':
	m[i][j] = -1;
	break;
      default:
	m[i][j] = c[j-1]-'0';
      }
    }
    scanf("\n");
  }
  for(i=1;i<=n;i++){
    t+=search(&xs,&ys,i);
    flush();
  }
  printf("%d\n",t);
  return 0;
}
