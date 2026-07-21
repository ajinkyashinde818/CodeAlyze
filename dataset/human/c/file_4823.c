#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
  int id;
  struct node *parent;
  struct node *sibling;
  struct node *child[2];
  int degree;
  int depth;
  int height;
  char *type;
} *nodePointer;
void init(nodePointer*,int);
nodePointer make1node(void);
void relationSet(nodePointer*,int,int*);
void calcStatus(nodePointer*,int);
int getDegree(nodePointer);
int getDepth(nodePointer);
int getHeight(nodePointer);
char *getType(nodePointer);
void printNodeArray(nodePointer*,int);
int main(void)
{
  int i;//counter
  int n;//the number of nodes
  int id;//node ID
  int childID[2];//node ID of child
  nodePointer *arr;//array of nodePointer
  scanf("%d",&n);
  arr=(nodePointer*)malloc(sizeof(nodePointer)*n);
  init(arr,n);
  for(i=0;i<n;i++)
    {
      scanf("%d%d%d",&id,&childID[0],&childID[1]);
      relationSet(arr,id,childID);
    }
  calcStatus(arr,n);
  printNodeArray(arr,n);
  return 0;
}
void init(nodePointer *arr,int n)
{
  int i;//counter
  for(i=0;i<n;i++)
    {
      arr[i]=make1node();
      arr[i]->id=i;
      arr[i]->parent=NULL;
      arr[i]->sibling=NULL;
      arr[i]->child[0]=NULL;
      arr[i]->child[1]=NULL;
      arr[i]->degree=-1;
      arr[i]->depth=-1;
      arr[i]->height=-1;
      arr[i]->type="";
    }
}
nodePointer make1node(void)
{
  nodePointer p=(nodePointer)malloc(sizeof(struct node));
  return p;
}
void relationSet(nodePointer *arr,int id,int *childID)
{
  int i;//counter
  for(i=0;i<2;i++)
    {
      if(childID[i]==-1) arr[id]->child[i]=NULL;
      else
	{
	  arr[id]->child[i]=arr[childID[i]];
	  arr[childID[i]]->parent=arr[id];
	}
    }
  if(arr[id]->child[0]!=NULL&&arr[id]->child[1]!=NULL)
    {
      arr[childID[0]]->sibling=arr[childID[1]];
      arr[childID[1]]->sibling=arr[childID[0]];
    }
}
void calcStatus(nodePointer *arr,int n)
{
  int i;//counter
  for(i=0;i<n;i++)
    {
      arr[i]->degree=getDegree(arr[i]);
      arr[i]->depth=getDepth(arr[i]);
      arr[i]->height=getHeight(arr[i]);
      arr[i]->type=getType(arr[i]);
    }
}
int getDegree(nodePointer p)
{
  int i;//counter
  int ret=0;//return number
  for(i=0;i<2;i++)
    {
      if(p->child[i]!=NULL) ret++;
    }
  return ret;
}
int getDepth(nodePointer p)
{
  if(p->parent==NULL) return 0;
  return 1+getDepth(p->parent);
}
int getHeight(nodePointer p)
{
  int i;//counter
  int ret[2];//return value(bigger one)
  for(i=0;i<2;i++)
    {
      if(p->child[i]==NULL) ret[i]=0;
      else ret[i]=1+getHeight(p->child[i]);
    }
  if(ret[0]>ret[1]) return ret[0];
  else return ret[1];
}
char *getType(nodePointer p)
{
  char *str[3]={"root","leaf","internal node"};
  if(p->parent==NULL) return str[0];
  if(p->child[0]==NULL&&p->child[1]==NULL) return str[1];
  return str[2];
}
void printNodeArray(nodePointer *arr,int n)
{
  int i;//counter
  for(i=0;i<n;i++)
    {
      printf("node %d: ",arr[i]->id);
      if(arr[i]->parent==NULL) printf("parent = -1, ");
      else printf("parent = %d, ",arr[i]->parent->id);
      if(arr[i]->sibling==NULL) printf("sibling = -1, ");
      else printf("sibling = %d, ",arr[i]->sibling->id);
      printf("degree = %d, ",arr[i]->degree);
      printf("depth = %d, ",arr[i]->depth);
      printf("height = %d, ",arr[i]->height);
      printf("%s",arr[i]->type);
      printf("\n");
    }
}
