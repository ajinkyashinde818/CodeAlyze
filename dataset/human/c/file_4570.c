#include<stdio.h>
#define N 100
typedef struct{
  int p,l,r;
}NODE;
int Depth(NODE *,int,int);
int Height(NODE *,int,int);
  int main(){
    int n,i,j,d,h,sum,id,l,r;
    NODE T[N];
    for(i=0;i<N;i++)
      T[i].p=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d%d%d",&id,&l,&r);
      T[l].p=id;
      T[r].p=id;
      T[id].l=l;
      T[id].r=r;
      
    }
    for(i=0;i<n;i++){
      printf("node %d: parent = %d, sibling = ",i,T[i].p);
      if(T[i].p==-1)
	printf("-1, degree = ");
      else if(T[T[i].p].l==i)
	printf("%d, degree = ",T[T[i].p].r);
      else if(T[T[i].p].r==i)
	printf("%d, degree = ",T[T[i].p].l);
      sum=0;
      if(T[i].l!=-1)
	sum++;
      if(T[i].r!=-1)
	sum++;
      printf("%d, depth = %d, height = %d, ",sum,Depth(T,i,0),Height(T,i,0));
      if(T[i].p==-1)
	printf("root\n");
      else if(sum!=0)
	printf("internal node\n");
      else
      printf("leaf\n");
      }
   
      

    return 0;
  }
int Depth(NODE T[],int i,int cnt){
  if(T[i].p==-1)
    return cnt;
  else
    return Depth(T,T[i].p,cnt+1);
}
int Height(NODE T[],int i,int cnt){
  int l=0,r=0;
  if(T[i].l==-1&&T[i].r==-1)
    return cnt;
  if(T[i].l!=-1)
    l=Height(T,T[i].l,cnt+1);
  if(T[i].r!=-1)
    r=Height(T,T[i].r,cnt+1);
  if(l>r)
    return l;
  else
    return r;
}
