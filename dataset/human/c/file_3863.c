#include<stdio.h>

#define SIZE 200000

int PAR1[SIZE],RANK1[SIZE];
int PAR2[SIZE],RANK2[SIZE];
int LIST[SIZE],NEXT[SIZE],G[SIZE],GC[SIZE],COUNT[SIZE];
void init_uf(int n){for(int i=0;i<n;i++){PAR1[i]=PAR2[i]=i;RANK1[i]=RANK2[i]=0;}}
int root1(int i){return PAR1[i]==i?i:(PAR1[i]=root1(PAR1[i]));}
int root2(int i){return PAR2[i]==i?i:(PAR2[i]=root2(PAR2[i]));}
int same1(int x,int y){return root1(x)==root1(y);}
int same2(int x,int y){return root2(x)==root2(y);}
void unite1(int x,int y){
  x=root1(x);y=root1(y);
  if(x==y)return;
  if(RANK1[x]<RANK1[y])PAR1[x]=y;
  else{PAR1[y]=x;if(RANK1[x]==RANK1[y])RANK1[x]++;}
}
void unite2(int x,int y){
  x=root2(x);y=root2(y);
  if(x==y)return;
  if(RANK2[x]<RANK2[y])PAR2[x]=y;
  else{PAR2[y]=x;if(RANK2[x]==RANK2[y])RANK2[x]++;}
}
void makelist(int n){
  int i,j;
  for(i=0;i<n;i++)LIST[i]=-1;
  for(i=0;i<n;i++){j=root1(i);NEXT[i]=LIST[j];LIST[j]=i;}
}
int main(){
  int n,k,l,i,j,a,b;
  scanf("%d%d%d",&n,&k,&l);
  init_uf(n);
  for(i=0;i<k;i++){scanf("%d%d",&a,&b);unite1(a-1,b-1);}
  for(i=0;i<l;i++){scanf("%d%d",&a,&b);unite2(a-1,b-1);}
  makelist(n);
  for(i=0;i<n;i++)G[i]=-1;
  for(i=0;i<n;i++)if(LIST[i]!=-1){
    for(j=LIST[i];j!=-1;j=NEXT[j]){
      a=root2(j);
      if(G[a]==i)GC[a]++;
      else{G[a]=i;GC[a]=1;}
    }
    for(j=LIST[i];j!=-1;j=NEXT[j])COUNT[j]=GC[root2(j)];
  }
  for(i=0;i<n;i++)printf("%d ",COUNT[i]);
}
