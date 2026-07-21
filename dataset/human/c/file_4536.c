#include <stdio.h>
#define N 25

typedef struct {
  int p, l, r, s;
}Node;

int depth(Node *,int,int);
int height(Node *,int,int,int);

int depth(Node *node,int num,int con){
  if(node[num].p==-1) return con;
  con++;
  con=depth(node,node[num].p,con);
  return con;
}

int height(Node *node,int num,int con,int max){
  if(node[num].l==-1&&node[num].r==-1){
    if(max<con) max=con;
    return max;
  }
  con++;
  if(node[num].l!=-1) max=height(node,node[num].l,con,max);
  if(node[num].r!=-1) max=height(node,node[num].r,con,max);
  con--;
  return max;
}

int main()
{
  int count,num,i,j,k,d_num,h_num;
  Node no[N];

  scanf("%d",&count);

  for(i=0;i<count;i++){
    no[i].p=-1;
  }

  for(i=0;i<count;i++){
    scanf("%d",&num);
    scanf("%d",&no[num].l);
    scanf("%d",&no[num].r);
    no[no[num].l].p=num;
    no[no[num].r].p=num;
  }

  for(i=0;i<count;i++){
    printf("node %d: parent = %d, ",i,no[i].p);
    if(no[i].p==-1) printf("sibling = -1, ");
    else if(no[no[i].p].l==-1&&no[no[i].p].r==-1) printf("sibling = -1, ");
    else if(no[no[i].p].l==i) printf("sibling = %d, ",no[no[i].p].r);
    else printf("sibling = %d, ",no[no[i].p].l);

    if(no[i].l==-1&&no[i].r==-1) printf("degree = 0, ");
    else if(no[i].l==-1||no[i].r==-1) printf("degree = 1, ");
    else printf("degree = 2, ");

    d_num=depth(no,i,0);
    h_num=height(no,i,0,0);
    
    printf("depth = %d, height = %d, ",d_num,h_num);

    if(no[i].p==-1) printf("root\n");
    else if(no[i].l==-1&&no[i].r==-1) printf("leaf\n");
    else printf("internal node\n");
  }

  return 0;
}
