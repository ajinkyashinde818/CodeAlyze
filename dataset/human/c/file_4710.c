#include<stdio.h>

typedef struct{
  int a;
  int b;
  int p;
  int s;
}P;
P T[25];
int C[25];
int H[25];
void print(int);
void rec(int,int);
int hei(int *,int);
int n;
int main(){
  int i,j,L,R,id,r,h;
  int c[25];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].a=T[i].b=T[i].p=T[i].s=-1;
  }
  for(i=0;i<n;i++){
    c[i]=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&L,&R);
    if(i==0){
      T[id].a=L;
      T[id].b=R;
      T[L].s=R;
      T[R].s=L;
      c[L]=id;
      c[R]=id;
      C[i]=0;
    }else{
      T[id].a=L;
      T[id].b=R;
      if(c[id]!=-1){
	T[id].p=c[id];
      }
      if(c[L]==-1){
	T[L].p=id;
      }
      if(c[R]==-1){
	T[R].p=id;
      }
      T[L].s=R;
      T[R].s=L;
      c[L]=id;
      c[R]=id;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p == -1){
      r = i;
    }
  }
  rec(r,0);
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}

void rec(int a,int b){
  C[a] = b;
  if(T[a].a != -1)rec(T[a].a,b+1);
  if(T[a].b != -1)rec(T[a].b,b+1);
}

void print(int a){
  int i,c=0,h;
  
  for(i=0;i<n;i++){
    if(T[i].p==a){
      c++;
    }
  }
  h=hei(H,a);
  
  if(T[a].p == -1){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n",a,T[a].p,T[a].s,c,C[a],H[a]);
  }else if(c == 0){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n",a,T[a].p,T[a].s,c,C[a],H[a]);
  }else{
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n",a,T[a].p,T[a].s,c,C[a],H[a]);
  }
}

int hei(int *H,int u){
  int h1,h2;
  h1=h2=0;
  if(T[u].b!=-1)h1=hei(H,T[u].b)+1;
  if(T[u].a!=-1)h2=hei(H,T[u].a)+1;
  if(h1<h2)h1=h2;
  return H[u]=h1;
}
