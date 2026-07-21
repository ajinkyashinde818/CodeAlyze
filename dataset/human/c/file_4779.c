#include <stdio.h>
#define MAX 100005
#define NIL -1
struct Nodes{
    int parent;
    int left;
    int right;
};
 
struct Nodes Node[MAX];
int Depth[MAX];
int Height[MAX];
 
int getS(int a){
    if(Node[a].parent == NIL)return NIL;
    if(Node[Node[a].parent].left!=a && Node[Node[a].parent].left != NIL){
        return Node[Node[a].parent].left;
    }
    if(Node[Node[a].parent].right!=a && Node[Node[a].parent].right != NIL){
        return Node[Node[a].parent].right;
    }
    return NIL;
}
void setD(int a,int b){
    if(a==NIL) return;
    Depth[a]=b;
    setD(Node[a].left,b+1);
    setD(Node[a].right,b+1);
}
 
int setH(int x){
  int a=0,b=0;
    if(Node[x].left!=NIL){
        a=setH(Node[x].left)+1;
    }
    if(Node[x].right!=NIL){
        b=setH(Node[x].right)+1;
    }
    if(a>b){
      return Height[x]=a;
    }else{
    return Height[x]=b;
    }
}
 
int main(){
  int left,right,a,n,root = 0,i,deg;
  scanf("%d",&n);
    for(i=0;i<n;++i){
        Node[i].parent=Node[i].left=Node[i].right = NIL;
    }
     
    for(i=0;i<n;++i){
      scanf("%d %d %d",&a,&left,&right);
        Node[a].left = left;
        Node[a].right = right;
        if(left!=NIL){
            Node[left].parent = a;
        }
        if(right!=NIL){
            Node[right].parent = a;
        }
    }
    for(i=0;i<n;++i){
        if(Node[i].parent==NIL){
            root=i;
        }
    }
    setD(root,0);
    setH(root);
     
    for(i=0;i<n;++i){
      printf("node %d: parent = %d, sibling = %d,"
	     ,i,Node[i].parent,getS(i));
      deg=0;
      if(Node[i].left!=NIL)deg++;
      if(Node[i].right!=NIL)deg++;
      printf(" degree = %d, depth = %d, height = %d,"
	     ,deg,Depth[i],Height[i]);
      if(Node[i].parent == NIL){
	printf(" root\n");
      }else if(Node[i].left==NIL&&Node[i].right==NIL){
	printf(" leaf\n");
      }else{
	printf(" internal node\n");
      }
    }
    
    return 0;
}
