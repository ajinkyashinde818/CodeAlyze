#include<stdio.h>

#define N 100001
#define Gard -1

typedef struct{
  int parent;
  int leftch;
  int rightch;
}Tree;

int main(){
  Tree Root[N];
  int loop,freq,chnode,numnode,temp,count,change,list;
  int i,j;

  scanf("%d",&loop);
  for(i=0;i<loop;i++){
    Root[i].parent=Gard;
    Root[i].leftch=Gard;
    Root[i].rightch=Gard;
  }

  for(i=0;i<loop;i++){
    scanf("%d %d",&freq,&chnode);
    
    for(j=0;j<chnode;j++){
      scanf("%d",&numnode);

      if(j==0){
	Root[freq].leftch=numnode;
	Root[numnode].parent=freq;
	temp=numnode;
      }

      else{
	Root[temp].rightch=numnode;
	Root[numnode].parent=freq;
	temp=numnode;
      }
    }
  }


  for(i=0;i<loop;i++){
    printf("node %d: parent = %d, ",i,Root[i].parent);

    count=0;
    change=i;
    while(Root[change].parent>Gard){
      change=Root[change].parent;
      count++;
    }
   
    printf("depth = %d, ",count);
    
    if(Root[i].parent==Gard){
      printf("root, [");
    }

    else if(Root[i].leftch==Gard){
      printf("leaf, [");
    }

    else{
      printf("internal node, [");
    }

    list=Root[i].leftch;
    count=0;
    while(list>Gard){
      if(count!=0){
	printf(", %d",list);
      }

      else{
	printf("%d",list);
      }
      count++;
      list=Root[list].rightch;
    }
    printf("]\n");
  }

  return 0;
}
