#include <stdio.h>
typedef struct {
  int parent;
  int child;
  int brother;

} node;

node n[100000];
int main()
{
  int a,c,d,e,i,j,num,depth;
  scanf("%d", &num);
  for(i=0;i<num;i++){
    n[i].parent=-1;
    n[i].brother=-1;
 n[i].child=-1;
  }
  for(i=0;i<num;i++){

    scanf("%d%d",&a,&c);

    for(j=0;j<c;j++){
      scanf("%d",&d);
      if(j==0)n[a].child=d;
      else n[e].brother=d;
      e=d;
      n[d].parent=a;
    }

  }
  for(i=0;i<num;i++){
    printf("node %d: parent = %d, depth = ",i,n[i].parent);
    c=n[i].parent;    
    depth=0;    
while(c!=-1){
depth++;
      c=n[c].parent;


}
    printf("%d, ",depth);

    if(n[i].parent==-1)
      printf("root, [");
    else if(n[i].child==-1)printf("leaf, [");
    else printf("internal node, [");





    if(n[i].child!=-1){
printf("%d",n[i].child);
      c=n[i].child;
      while(1){ 
	if(n[c].brother!=-1){  
	  printf(", %d",n[c].brother);
	  c=n[c].brother;

	}
	else break;
      }}
      printf("]\n");

    }

    return 0;
  }
