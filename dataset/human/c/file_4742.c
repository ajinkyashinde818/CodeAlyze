#include<stdio.h>
#define N 100000

typedef struct Ki{
  int p;
  int r;
  int l;
  int h;
}tree;

int n;
tree T[N];

void sibling(int i){
  int j;
  for(j=0;j<n;j++){
    if(T[i].p == -1){
      printf("-1");
      break;
    }
    else if(T[i].p==T[j].p&&i != j){
      printf("%d",j);
      break;
    }
    if(j==n-1)printf("-1");
      
  }
}



int depth(int i){
  int count=0,iNoOya;
  iNoOya=i;
  while(1){
    if(T[iNoOya].p==-1) break;
    iNoOya=T[iNoOya].p;
    count++;
    
  }
  return count;
}

void hantei(int i){
  if( T[i].p == -1)printf("root");
  else if(T[i].p!=-1 && T[i].h==0) printf("leaf");
  else printf("internal node");
  printf("\n");
}

int degree(int i){
  int j,count=0;
  for(j=0;j<n;j++){
    if(T[j].p==i) count++;
  }
  return count;
}

int height(int i){
  int j,left,right,a,b;
  if(T[i].h==-1){
    if(T[i].l==-1 && T[i].r==-1){
      T[i].h=0;
    }
    else{
      
      if(T[i].l!=-1){
	left = T[i].l;
	a = height(left);
      }
      
      else a = 0;
      
      if(T[i].r!=-1){
	right = T[i].r;
	b = height(right);
      }
      else b = 0; 
      
      if(a==b) T[i].h = a+1;
      if(a>b) T[i].h = a+1;
      if(a<b) T[i].h = b+1;
    }
  }
  return T[i].h;
}




int main(){
  int i,id,left,right;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p = -1;
    T[i].l = -1;
    T[i].r = -1;
    T[i].h = -1;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&left,&right);
    T[id].r = right;
    T[right].p = id;
    T[id].l = left;
    T[left].p = id;
  }
  
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = ",i,T[i].p);
    sibling(i);
    printf(", degree = %d, depth = %d, height = %d, ",degree(i),depth(i),height(i));
    hantei(i);
  }
  return 0;
}
