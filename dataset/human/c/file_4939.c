#include <stdio.h>
#define MAX 10000

typedef struct{
  int p;
  int l;
  int r;
}Node;

void getDepth(Node*,int,int,int*);
int getSibling(Node*,int);
int getHeight(Node*,int);

int main(){
  int n,i,j,num,d,q[2],D[MAX],c[MAX];
  Node data[MAX];


  scanf("%d",&n);
   for(i=0;i<n;i++){
    data[i].p=-1;
    data[i].l=-1;
    data[i].r=-1;
    D[i]=0;
   }

  for(i=0;i<n;i++){

    scanf("%d",&num);
    scanf("%d%d",&q[0],&q[1]);
        data[num].l=q[0];
        data[num].r=q[1];
         
        if(q[0]!=-1) {
            data[q[0]].p=num;
            c[num]++;
        }
        if(q[1]!=-1) {
            data[q[1]].p=num;
            c[num]++;
        }
    }

  

 for(i=0;i<n;i++){
   if(data[i].p==-1){
     d=i;
    }
 }
  getDepth(data,d,0,D);


  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, ",i,data[i].p,getSibling(data,i),c[i]);
    printf("depth = %d, height = %d, ",D[i],getHeight(data,i));
    if(data[i].p==-1){
      printf("root\n");
    }else if(data[i].l==-1&&data[i].r==-1){
      printf("leaf\n");
      continue;
    }else{
      printf("internal node\n");
    }
  }

  return 0;
}

void getDepth(Node *data,int x,int j,int *D){
   D[x]=j;
   if(data[x].r!=-1){
     getDepth(data,data[x].r,j+1,D);                               
   }
   if(data[x].l!=-1){
     getDepth(data,data[x].l,j+1,D);                                 
   }

}

int getSibling(Node *data,int x){
    
    if(data[x].p==-1) return -1;
    if(data[data[x].p].l!=x&&data[data[x].p].l!=-1)
    return data[data[x].p].l;
    if(data[data[x].p].r!=x&&data[data[x].p].r!=-1)
    return data[data[x].p].r;
    return -1;
}

 int getHeight(Node *data,int x){
     int h1=0,h2=0;
     if(data[x].l!=-1)
     h1=getHeight(data,data[x].l)+1;
     if(data[x].r!=-1)
     h2=getHeight(data,data[x].r)+1;

     if(h2<h1) return h1;
     else return h2;
 }
