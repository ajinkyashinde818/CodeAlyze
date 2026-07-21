#include <stdio.h>
#define max 25
#define nil -1
typedef struct{
  int prev;
  int right;
  int left;
  int sibling;
  int degree;
  int Depth;
  int Height;
} node;
void printData(void);
void HowDepth(int, int);
int HowHeight(int);
int n;
node data[max];

int main()
{
  int i, id;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    data[i].prev = nil;
    data[i].sibling = nil;
    data[i].degree = 0; }
  
  for(i = 0 ; i < n ; i++){
    scanf("%d",&id);
    scanf("%d%d",&data[id].left,&data[id].right);
    if(data[id].left != nil){
      data[data[id].left].prev = id;
      data[id].degree++; }
    if(data[id].right != nil){
      data[data[id].right].prev = id;
      data[id].degree++; }
    if(data[id].left != nil && data[id].right != nil){
      data[data[id].left].sibling = data[id].right;
      data[data[id].right].sibling = data[id].left; }
  } 
  
  for(i = 0 ; i < n ; i++){
    if(data[i].prev == nil){
      HowDepth(i,0);
      break; }
  }

  for(i = 0 ; i < n ; i++) data[i].Height = HowHeight(i);
  printData();

  return 0;
}

void printData(void)
{
  int i; 

  for(i = 0 ; i < n ; i++){
    printf("node %d: ",i);
    printf("parent = %d, ",data[i].prev);
    printf("sibling = %d, ",data[i].sibling);
    printf("degree = %d, ",data[i].degree); 
    printf("depth = %d, ",data[i].Depth);
    printf("height = %d, ",data[i].Height);
    if(data[i].prev == nil) printf("root\n");
    else if(data[i].right == nil && data[i].left == nil) printf("leaf\n");
    else printf("internal node\n"); }
}

void HowDepth(int i, int count)
{
  data[i].Depth = count;
  if(data[i].right != nil) HowDepth(data[i].right,count + 1);
  if(data[i].left != nil) HowDepth(data[i].left, count + 1);
}

int HowHeight(int i)
{
  int H1 = 0, H2 = 0;
      
  if(data[i].right != nil) H1 = HowHeight(data[i].right) + 1;
  if(data[i].left != nil) H2 = HowHeight(data[i].left) + 1; 

  if(H1 >= H2) return H1;
  if(H1 < H2) return  H2;
}
