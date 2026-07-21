#include<stdio.h>
#include <stdlib.h>
typedef struct{
  int id,parent,depth,type; //type:0,root,1,internal node, 2,leaf
  int num; //nimber of data
  int *data;
}treenode;
int main(){
  int n,d,i,j,k,id;
  int cnt = 1;
  char ttype[3][20] = {"root","internal node","leaf"};
  treenode *a;
  scanf("%d",&n);
  a = (treenode *)malloc(sizeof(treenode)*n);
  for(i =0;i < n;i++){
    scanf("%d %d",&id,&j);
    a[id].id = id;
    a[id].num = j;
    a[id].data = malloc(sizeof(int)*j);
    a[id].depth = 0;
    a[id].parent = -1;
    for(k =0;k <j;k++){
       scanf("%d",&a[id].data[k]);
     }
  }
  while(cnt != 0){
    cnt = 0;
    for(i =0;i < n;i++){
      for(k =0;k < a[i].num;k++){
        a[a[i].data[k]].parent = a[i].id;
        if(a[a[i].data[k]].depth != a[i].depth + 1){
          a[a[i].data[k]].depth = a[i].depth + 1;
          cnt++;
        }
      }
    }
 }
  for(i =0;i < n;i++){
    if(a[i].parent == -1)  a[i].type = 0;
    else if(a[i].num == 0)  a[i].type = 2;
    else a[i].type = 1;
    printf("node %d: parent = %d, depth = %d, %s, [",a[i].id,a[i].parent,a[i].depth,ttype[a[i].type]);
    if(a[i].num != 0){
      for(j =0;j < a[i].num - 1;j++) printf("%d, ",a[i].data[j]);
      printf("%d]\n",a[i].data[j]);
    }else printf("]\n");
  }
  return 0;
}
