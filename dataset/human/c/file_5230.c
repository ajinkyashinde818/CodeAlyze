#include<stdio.h>
#include<stdlib.h>


typedef struct{
  int p, l, r;
}node;

node *data;

int dep(int n){
  int d=0;

  for(n=data[n].p;n!=-1;n=data[n].p) d++;

  return d;
}

int hei(int n){
  int a=0, b=0;

  if(data[n].l!=-1) a=hei(data[n].l)+1;
  if(data[n].r!=-1) b=hei(data[n].r)+1;

  if(a>b) return a;
  else return b;
}

int main(){
  int i, a, c, n;
  
  scanf("%d",&n);
  
  data=(node *)malloc(sizeof(node)*n);
  
  for(i=0;i<n;i++) data[i].p=-1;
  
  for(i=0;i<n;i++){
    
    scanf("%d",&a);
    
    scanf(" %d %d",&data[a].l,&data[a].r);
    
    data[data[a].l].p=a;
    
    data[data[a].r].p=a;
  }


  for(i=0;i<n;i++){
    c=0;
    
    printf("node %d: parent = %d, sibling = ",i,data[i].p);
    
    if(data[i].p==-1) printf("-1, ");
    
    else if(data[data[i].p].l!=i) printf("%d, ",data[data[i].p].l);
    
    else printf("%d, ",data[data[i].p].r);

    
    if(data[i].l!=-1) c++;
    
    if(data[i].r!=-1) c++;
    
    printf("degree = %d, depth = %d, height = %d, ",c,dep(i),hei(i));

    
    if(data[i].p==-1) printf("root\n");
    
    else if(c == 0) printf("leaf\n");
    
    else printf("internal node\n");
  }

 
  return 0;
}
