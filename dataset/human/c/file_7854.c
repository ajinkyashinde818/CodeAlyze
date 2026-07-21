#include<stdio.h>
#include<stdlib.h>

struct TQueue{
  int x,y,dep;
  struct TQueue* next;
};

void allfree(struct TQueue* q){
  struct TQueue* r[2];
  r[0]=q;
  if(q==0)return;
  r[1]=q->next;
  while(r[1]){
    free(r[0]);
    r[0]=r[1];
    r[1]=r[1]->next;
  }
  free(r[0]);
}

struct TQueue* push(struct TQueue* ed,int y,int x,int d){
  if(ed==0){
    return 0;
  }
  ed->next=(struct TQueue*)malloc(sizeof(struct TQueue));
  ed->next->next=0;
  ed->next->dep=d;
  ed->next->x=x;
  ed->next->y=y;
  return ed->next;
}

struct TQueue* Queue(int y,int x,int d){
  struct TQueue* ret;
  ret=(struct TQueue*)malloc(sizeof(struct TQueue));
  ret->next=0;
  ret->x=x;
  ret->y=y;
  ret->dep=d;
  return ret;
}


struct TQueue* delhead(struct TQueue* st){
  struct TQueue* ret;
  if(!st)return 0;
  ret=st->next;
  free(st);
  return ret;
}




int main(){
  int w,h,n;
  int i,j,k;
  char* s;
  int mp[1000][1000];
  int ts[1002][1002];
  int ret,ls,pt;
  int gy[10],gx[10];
  struct TQueue *st,*ed;
  s=(char*)malloc(sizeof(char)*1001);

  gets(s);
  sscanf(s,"%d %d %d",&h,&w,&n);

  for(i=0;i<h;i++){
    gets(s);
    for(j=0;j<w;j++){
      mp[i][j]=s[j]=='X'?1:0;
      if(s[j]>='1'&&s[j]<='9'){
        gy[s[j]-'0']=i+1;
        gx[s[j]-'0']=j+1;
      }
      if(s[j]=='S'){
        gy[0]=i+1;
        gx[0]=j+1;
      }
    }
  }
  for(i=0;i<h+2;i++){
    ts[i][0]=1;
    ts[i][w+1]=1;
  }
  for(j=0;j<w+2;j++){
    ts[0][j]=1;
    ts[h+1][j]=1;
  }
  ret=0;
  for(k=0;k<n;k++){
    st=Queue(gy[k],gx[k],ret);
    ed=st;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        ts[i+1][j+1]=mp[i][j];
      }
    }

    while(st){
      if(((st->y+1==gy[k+1]||st->y-1==gy[k+1])&&st->x==gx[k+1])
        ||((st->x+1==gx[k+1]||st->x-1==gx[k+1])&&st->y==gy[k+1])){
        break;
      }
      if(ts[st->y+1][st->x]==0){
        ts[st->y+1][st->x]=1;
        ed=push(ed,st->y+1,st->x,st->dep+1);
      }
      if(!ts[st->y-1][st->x]){
        ts[st->y-1][st->x]=1;
        ed=push(ed,st->y-1,st->x,st->dep+1);   
      }
      if(!ts[st->y][st->x-1]){
        ts[st->y][st->x-1]=1;
        ed=push(ed,st->y,st->x-1,st->dep+1);
      }
      if(!ts[st->y][st->x+1]){
        ts[st->y][st->x+1]=1;
        ed=push(ed,st->y,st->x+1,st->dep+1);
      }
      st=delhead(st);
    }
    if(st){
      ret=st->dep+1;
      allfree(st);
    }else{
      printf("Incorrect Data\n");
      return 0;
    }
  }

  printf("%d\n",ret);
  return 0;
}
