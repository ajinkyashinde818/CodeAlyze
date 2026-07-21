#include <stdio.h>

#define MAX 100000

int depth(int);
int hei(int,int);
int deg(int);

typedef struct{
  int le,ri,pa;
}data;

data Da[MAX];
int De[MAX];

int main(){
  int n,id,bufi,le,ri,chk=0;
  int i,j;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++) Da[i].pa=Da[i].le=Da[i].ri=-1;
  for(i=0;i<n;i++){
    scanf("%d",&id);    
    for(j=0;j<2;j++){
      scanf("%d",&bufi);      
      if(j==0)Da[id].le=bufi;
      else Da[id].ri=bufi;      
      le=bufi;      
      if(le>=0)Da[bufi].pa=id;     
    }
  }
  
  for(i=0;i<n;i++){    
    printf("node %d: ",i);
    printf("parent = %d, ",Da[i].pa);

    if(Da[i].pa==-1) printf("sibling = -1, ");
    else {
      if(Da[Da[i].pa].le!=i&&Da[Da[i].pa].le!=-1) printf("sibling = %d, ",Da[Da[i].pa].le);//sibling
      else if(Da[Da[i].pa].ri!=i&&Da[Da[i].pa].ri!=-1)printf("sibling = %d, ",Da[Da[i].pa].ri);
      else printf("sibling = -1, ");
    }
    
    printf("degree = %d, ",deg(i));//degree
    
    printf("depth = %d, ", depth(i));

    printf("height = %d, ",hei(i,0));
    
    if(Da[i].pa==-1) printf("root");
    else if(Da[i].le==-1&&Da[i].ri==-1) printf("leaf");
    else printf("internal node");
    printf("\n");
  }
  
  return 0;
}

int depth(int a){
  int count = 0;

  while(Da[a].pa!=-1){
    count++;
    a=Da[a].pa;
  }

  return count;
}

int hei(int i,int cnt){
  int a,b;
  if(deg(i)==2){
    cnt++;
    a=hei(Da[i].ri,cnt);
    b=hei(Da[i].le,cnt);

    if(a>=b) return a;
    else return b;
  }

  else if(deg(i)==1){
    cnt++;
    if(Da[i].ri!=-1) return hei(Da[i].ri,cnt);
    if(Da[i].le!=-1) return hei(Da[i].le,cnt);
    return cnt;
  }
  else return cnt;
}

int deg(int i){
  int chk=0;                        
  if(Da[i].ri!=-1) chk++;
  if(Da[i].le!=-1) chk++;
  return chk;
}
