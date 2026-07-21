#include<stdio.h>

typedef struct{
  int x;
  int y;
} point;

int smaller(int a,int b){
  if(a<b){
    return a;
  }
  else{
    return b;
  }
}

int count(point s,point g){
  if((s.x>g.x)&&(s.y>g.y)){
    return count(g,s);
  }
  else if((s.x<g.x)&&(s.y<g.y)){
    int tlt=smaller(g.x-s.x,g.y-s.y);
    point ns={s.x+tlt,s.y+tlt};
    return tlt+count(ns,g);
  }
  else{
    return abs(s.x-g.x)+abs(s.y-g.y);
  }
}

void doit(int w,int h,int n){
  point st;
  point gl;
  int i;
  int ans=0;
  scanf("%d %d",&st.x,&st.y);
  for(i=1;i<n;i++){
    scanf("%d %d",&gl.x,&gl.y);
    ans+=count(st,gl);
    st=gl;
  }
  printf("%d\n",ans);
}

int main(){
  int w,h;
  int n;
  scanf("%d %d %d",&w,&h,&n);
  doit(w,h,n);
  return 0;
}
