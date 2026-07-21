#include <stdio.h>
#define nil -100
#define max 100000
void printData(void);
void HowDepth(int, int);
struct Node{
  int prev;
  int left;
  int right;
  int k;
  int Depth;
};
typedef struct Node Node;
Node data[max];
int n;
int main()
{
  int i, j, id, keep, in;

  scanf("%d",&n);
  
  for(i = 0 ; i < n ; i++) data[i].prev = -1;
  for(i = 0 ; i < n ; i++){
    data[i].left = nil;
    data[i].right = nil; }
  
  for(i = 0 ; i < n ; i++){
    scanf("%d",&id);
    scanf("%d",&data[id].k);

    keep = nil;
    for(j = 0 ; j < data[id].k ; j++){
      keep = in;
      scanf("%d",&in);
      if(j == 0){
	data[id].left = in;
	data[data[id].left].prev = id; }
      if(j > 0){
	data[keep].right = in;
	data[data[keep].right].prev = id; }
    }
  }

  for(i = 0 ; i < n ; i++){
    if(data[i].prev == -1){
      HowDepth(i,0);
      break; }
  }
  
  printData();  
    
  return 0;
}

void HowDepth(int i, int count)
{
  data[i].Depth = count;
  if(data[i].right != nil) HowDepth(data[i].right, count);
  if(data[i].left != nil) HowDepth(data[i].left, ++count);
}

void printData(void)
{
  int i, j, keep;
  for(i = 0 ; i < n ; i++){
    printf("node %d: parent = %d, depth = %d, ",i,data[i].prev,data[i].Depth);
    if(data[i].prev == -1) printf("root, ");
    else if(data[i].k == 0) printf("leaf, ");
    else printf("internal node, ");

    if(data[i].k != 0){
      printf("[%d",data[i].left);
      keep = data[i].left;
      for(j = 0 ; j < data[i].k-1 ;j++){
	printf(", %d",data[keep].right);
	keep = data[keep].right; }
      printf("]\n"); }
    else printf("[]\n");
  }
	
}
