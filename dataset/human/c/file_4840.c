#include<stdio.h>
struct Node{
  int a,b,c;
};
struct Node N[10000];
int depth(int);
int sibling(int);
int n;
int D[10000],S[10000];
int main(){
  int i,j,k,l,m,q,r,s;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    N[i].a=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&q,&r,&s);
    N[q].b=r;
    N[q].c=s;
    if(r!=-1){
      N[r].a=q;
    }
    if(s!=-1){
      N[s].a=q;
    }
  }
  for(i=0;i<n;i++){
    D[i]=depth(i);
    S[i]=0;
  }
  for(i=0;i<n;i++){
    if(N[i].b==-1 && N[i].c==-1){
      S[i]=0;
      k=N[i].a;
      l=1;
      while(1){
        if(k==-1){
          break;
        }
        if(S[k]<l){
          S[k]=l;
        }
        l++;
        k=N[k].a;
      }
    }
  }
  for(i=0;i<n;i++){
    j=0;
    printf("node %d: ",i);
    printf("parent = %d, ",N[i].a);
    printf("sibling = %d, ",sibling(i));
    if(N[i].b!=-1){
      j++;
    }
    if(N[i].c!=-1){
      j++;
    }
    printf("degree = %d, ",j);
    printf("depth = %d, ",D[i]);
    printf("height = %d, ",S[i]);
    if(N[i].a==-1){
      printf("root\n");
    }
    else if(N[i].b==-1 && N[i].c==-1){
      printf("leaf\n");
    }
    else{
      printf("internal node\n");
    }
    }
    return 0;
}

int depth(int r){
  int c=0;
  while(1){
    r=N[r].a;
    if(r==-1){
      break;
    }
    c++;
  }
  return c;
}

int sibling(int s){
  if(N[s].a==-1){
    return -1;
  }
  if(N[N[s].a].b!=s && N[N[s].a].b!=-1){
    return N[N[s].a].b;
  }
  if(N[N[s].a].c!=s && N[N[s].a].c!=-1){
    return N[N[s].a].c;
  }
  return -1;
}
