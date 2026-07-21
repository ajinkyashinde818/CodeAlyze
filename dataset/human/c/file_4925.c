#include<stdio.h>
#include<stdlib.h>
  
#define MAX 100000
#define NLL -1

struct Node {
  	
int p,l,r;
	
};

struct Node nd[MAX];

int n,a[MAX],b[MAX];

void dpth(int x,int y){
if(x==NLL)return;
a[x]=y;
dpth(nd[x].l,y+1);
dpth(nd[x].r,y+1);
}

int hght(int z){
int h1=0,h2=0;
if(nd[z].l!=NLL) h1=hght(nd[z].l)+1;
if(nd[z].r!=NLL) h2=hght(nd[z].r)+1;
return b[z]=(h1>h2?h1:h2);
}
int sibling(int a){
if(nd[a].p==NLL)return NLL;
if(nd[nd[a].p].l!=a&&nd[nd[a].p].l!=NLL)return nd[nd[a].p].l;
if(nd[nd[a].p].r!=a&&nd[nd[a].p].r!=NLL)return nd[nd[a].p].r;
return NLL;
}


void print(int x){
int i,c;

printf("node %d: ",x);
printf("parent = %d, ",nd[x].p);
printf("sibling = %d, ",sibling(x));

int degree=0;

if(nd[x].l!=NLL)degree++;
if(nd[x].r!=NLL)degree++;

printf("degree = %d, ",degree);
printf("depth = %d, ",a[x]);
printf("height = %d, ",b[x]);

if(nd[x].p==NLL)printf("root\n");
else if(nd[x].l==NLL&&nd[x].r==NLL) printf("leaf\n");
else  printf("internal node\n");
}

int main(){
int s,l,r,root=0,i;

scanf("%d",&n);

for(i=0;i<n;i++){
nd[i].p=NLL;
}

for(i=0;i<n;i++){
scanf("%d",&s);
scanf("%d",&l);
scanf("%d",&r);

nd[s].l=l;
nd[s].r=r;

if(l!=NLL)nd[l].p=s;
if(r!=NLL)nd[r].p=s;
}

for(i=0;i<n;i++){
if(nd[i].p==NLL)root=i;
}

dpth(root,0);

hght(root);
for(i=0;i<n;i++)print(i);
return 0;
}
