#include <stdio.h>
#define NIL -1

struct node{
    int parent;
    int left;
    int right;
};

struct node t[100000];
int n,d[100000],h[100000];

int sethei(int u)
{
int h1=0,h2=0;
if(t[u].right!=NIL){
    h1=sethei(t[u].right)+1;
}
if(t[u].left!=NIL){
    h2=sethei(t[u].left)+1;
}
return h[u]=(h1>h2 ? h1:h2);
}

void setdep(int u,int p)
{
    if(u==NIL) return;
    d[u]=p;
    setdep(t[u].right,p+1);
    setdep(t[u].left,p+1);
}

int setsib(int u)
{
if(t[u].parent==NIL){
    return NIL;
}    
if(t[t[u].parent].left !=u && t[t[u].parent].left !=NIL){
    return t[t[u].parent].left;
}
if(t[t[u].parent].right !=u && t[t[u].parent].right !=NIL){
    return t[t[u].parent].right;
}
return NIL;
}

void print(int u)
{
int i,c,deg=0;

printf("node %d: parent = %d, sibling = %d, ",u,t[u].parent,setsib(u));
if(t[u].left!=NIL) deg++;
if(t[u].right!=NIL) deg++;
printf("degree = %d, depth = %d, height = %d, ",deg,d[u],h[u]);

if(t[u].parent ==NIL) printf("root\n");
else if(t[u].left == NIL && t[u].right == NIL) printf("leaf\n");
else printf("internal node\n");

}

int main(){
int n,id,l,r,i,root=0;

scanf("%d",&n);
for(i=0;i<n;i++){
    t[i].parent=NIL;
}
for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d %d",&l,&r);
    t[id].left=l;
    t[id].right=r;
    if(l!=NIL) t[l].parent=id;
    if(r!=NIL) t[r].parent=id;
}
for(i=0;i<n;i++){
if(t[i].parent==NIL) root=i;
}

setdep(root,0);
sethei(root);

for(i=0;i<n;i++){
    print(i);
}
return 0;
 }
