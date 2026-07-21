#include<stdio.h>

#define N 100001
#define Gard -1

typedef struct{
  int parent;
  int leftch;
  int rightch;
}Tree;

int Calheight(int );

Tree Binary[N];

int main(){
  int loop,freq,lchild,rchild,count,change;
  int i;
  
  scanf("%d",&loop);
  for(i=0;i<loop;i++){
    Binary[i].parent=Gard;
  }
  
  for(i=0;i<loop;i++){
    scanf("%d %d %d",&freq,&lchild,&rchild);
    Binary[freq].leftch=lchild;
    Binary[freq].rightch=rchild;
    
    if(lchild!=Gard){
      Binary[lchild].parent=freq;
    }
    
    if(rchild!=Gard){
      Binary[rchild].parent=freq;
    }
  }
  
  for(i=0;i<loop;i++){
    printf("node %d: parent = %d, ",i,Binary[i].parent);

    if(Binary[i].parent==Gard){
      printf("sibling = %d, ",Gard);
    }
    
    else if((Binary[Binary[i].parent].leftch!=i) && (Binary[Binary[i].parent].leftch!=Gard)){
      printf("sibling = %d, ",Binary[Binary[i].parent].leftch);
    }
    
    else if((Binary[Binary[i].parent].rightch!=i) && (Binary[Binary[i].parent].rightch!=Gard)){
      printf("sibling = %d, ",Binary[Binary[i].parent].rightch);
    }

    else{
      printf("sibling = %d, ",Gard);
    }

    count=0;
    if(Binary[i].leftch!=Gard){
      count++;
    }

    if(Binary[i].rightch!=Gard){
      count++;
    }

    printf("degree = %d, ",count);

    count=0;
    change=i;
    while(Binary[change].parent>Gard){
      change=Binary[change].parent;
      count++;
    }
   
    printf("depth = %d, ",count);

    printf("height = %d, ",Calheight(i));
    
    if(Binary[i].parent==Gard){
      printf("root\n");
    }

    else if((Binary[i].leftch==Gard) && (Binary[i].rightch==Gard)){
      printf("leaf\n");
    }

    else{
      printf("internal node\n");
    }
						     
  }
  return 0;
}

int Calheight(int i){
  int height1=0;
  int height2=0;

  if(Binary[i].leftch!=Gard){
    height1=Calheight(Binary[i].leftch)+1;
  }
  
  if(Binary[i].rightch!=Gard){
    height2=Calheight(Binary[i].rightch)+1;
  }


  if(height1>=height2){
    return height1;
  }

  else{
    return height2;
  }
}
