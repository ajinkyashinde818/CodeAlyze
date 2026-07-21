//2020.1.6
//s1270188 xxxmk2
//alds1_07b

#include<stdio.h>
#include<stdlib.h>

//struct
typedef struct{
  int p, l, r;
}node;

//prototype
int depth(int);
int height(int);


//global
node *data;

int main(){
  int i, a, cnt, num;

  //input
  scanf("%d",&num);
  data=(node *)malloc(sizeof(node)*num);
  for(i=0;i<num;i++) data[i].p=-1;
  for(i=0;i<num;i++){
    scanf("%d",&a);
    scanf(" %d %d",&data[a].l,&data[a].r);
    data[data[a].l].p=a;
    data[data[a].r].p=a;
  }

  //output
  for(i=0;i<num;i++){
    printf("node %d: parent = %d, sibling = ",i,data[i].p);
    if(data[i].p==-1) printf("-1, ");
    else if(data[data[i].p].l!=i) printf("%d, ",data[data[i].p].l);
    else printf("%d, ",data[data[i].p].r);

    cnt=0;
    if(data[i].l!=-1) cnt++;
    if(data[i].r!=-1) cnt++;
    printf("degree = %d, depth = %d, height = %d, ",cnt,depth(i),height(i));

    
    if(data[i].p==-1) printf("root\n");
    else if(cnt==0) printf("leaf\n");
    else printf("internal node\n");
  }

  free(data);
  return 0;
}

int depth(int n){
  int d=0;

  for(n=data[n].p;n!=-1;n=data[n].p) d++;

  return d;
}

int height(int n){
  int a=0, b=0;

  if(data[n].l!=-1) a=height(data[n].l)+1;
  if(data[n].r!=-1) b=height(data[n].r)+1;

  if(a>b) return a;
  else return b;
}
