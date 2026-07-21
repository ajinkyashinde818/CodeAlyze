#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30

typedef struct node{
 int id;
 int pareid;
 int sibid;
 int degree;/*子供の数*/
 int depth;
 int height;
 char type[20];
 struct node *left;
 struct node *right;
}node;









int depthcheck(node N[],int i){

 if(N[i].pareid==-1)return 0;
 else{return depthcheck(N,N[i].pareid)+1;}

}


void heightcheck(node N[],int id){
 if(N[id].pareid==-1){return;}
 else if(N[N[id].pareid].height <= N[id].height+1){
    N[N[id].pareid].height=N[id].height+1;
    heightcheck(N,N[id].pareid);}


}



int main(){
int i,n;
int x,y,z;
node N[MAX];



scanf("%d",&n);

for(i=0;i<n;i++){
 N[i].id=-1;
 N[i].pareid=-1;
 N[i].sibid=-1;
 N[i].degree=-1;
 N[i].depth=-1;
 N[i].height=-1;
 N[i].left=NULL;
 N[i].right=NULL;

}


for(i=0;i<n;i++){

 scanf("%d",&x);
 N[x].id=x;

 scanf("%d %d",&y,&z);
 if(y!=-1&&z!=-1){
   N[y].pareid=x;
   N[y].sibid=z;
   N[z].pareid=x;
   N[z].sibid=y;
   N[x].degree=2;
   N[x].left=&N[y];
   N[x].right=&N[z];
  }
 else if(y==-1&&z==-1){
   N[x].degree=0;
   N[x].height=0;
   strncpy(N[x].type,"leaf",4);N[x].type[4]='\0';
 }
 else{
    if(z==-1){
     N[y].pareid=x;
     N[y].sibid=-1;
     N[x].left=&N[y];
    }
    else{
     N[z].pareid=x;
     N[z].sibid=-1;
     N[x].right=&N[z];
    }
  N[x].degree=1;
 }

}

/*root探索*/
for(i=0;i<n;i++){
 if(N[i].pareid==-1){strncpy(N[i].type,"root",4);N[x].type[4]='\0';break;}
}
/*-----------*/


for(i=0;i<n;i++){
 
if(N[i].degree==0){heightcheck(N,i);}


}

for(i=0;i<n;i++){
 N[i].depth=depthcheck(N,i);
 if(N[i].type[0]!='r'&&N[i].type[0]!='l'){strncpy(N[i].type,"internal node",13);N[i].type[13]='\0';}
 printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",i,N[i].pareid,N[i].sibid,N[i].degree,N[i].depth,N[i].height,N[i].type);
}


return 0;
}

/*あってるのにちがうって出る*/
