#include<stdio.h>
#define N 25
#define NIL -1

typedef struct{

  int pid;//親のID
  int leftc;//自分の子供の一番左の子
  int rights;//自分のすぐ右隣の兄弟
  
}Rooted;

int sibling(int);
int degree(int);
int depth(int);
int height(int);
int type(int);

Rooted data[N];

int main(){

  int i,j,t,n,l,r,id,root;

  scanf("%d",&n);//接点の数

  for(i=0;i<N;i++){
    data[i].pid=NIL;
    data[i].leftc=NIL;
    data[i].rights=NIL;
  }

  for(i=0;i<n;i++){

    scanf("%d%d%d",&id,&l,&r);

    data[l].pid=id;
    data[r].pid=id;
    data[id].leftc=l;
    data[l].rights=r;

  }//for


  for(i=0;i<n;i++){

    printf("node %d: ",i);

    printf("parent = %d, ",data[i].pid);

    printf("sibling = %d, ",sibling(i));

    printf("degree = %d, ",degree(i));

    printf("depth = %d, ",depth(i));

    printf("height = %d, ",height(i));
    
    t=type(i);
    if(t==-1) printf("root\n");
    else if(t==0) printf("leaf\n");
    else printf("internal node\n");

  }//for

  return 0;
  
}

int sibling(int i){

  if(data[i].pid==NIL) return NIL;
  
  if(data[data[i].pid].leftc==i){

    return data[i].rights;
    
  }else{

    return data[data[i].pid].leftc;
    
  }
  
}

int degree(int i){
  
  int deg=0,j;

  for(j=0;j<N;j++){

    if(data[j].pid==i){
      deg++;
    }
    
  }
 
  return deg;
  
}

int depth(int i){

  int dep=0;

  while(data[i].pid!=NIL){

    i=data[i].pid;
    dep++;
    
  }//while

  return dep;
  
}

int height(int i){

  int h=-1;
  int temp,j;

  for(j=0;j<N;j++){

    if(data[j].pid==i){

      temp=height(j);

      if(temp>h){
	h=temp;
      }
      
    }//if
    
  }//for

  h++;
  return h;

}

int type(int i){
  if(data[i].pid==-1) return -1;
  else if(height(i)==0) return 0; 
  else return 2;
}
