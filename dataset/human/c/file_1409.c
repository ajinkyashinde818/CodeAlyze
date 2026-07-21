#include<stdio.h>
int main(){
  int n,m,i,a,b,c,d=1,s;
  char w;
  scanf("%d",&n);
  while(n--){
    scanf("%d\n",&m);
    s=3*m+2;
    d=1;
    for(i=0;i<4*m;i++){
      scanf("%c",&w);
      if(w=='N')a=1;
      else      a=0;
      if     (i==0)b=a;
      else if(i==2*m-1)c=a;
      else if(i==2*m){//printf("\n");
	if(a){
	  s--;
	  if(b)s--;
	}
      }
      else if(i==4*m-1){
	if(a){
	  s--;
	  if(c)s--;
	}
      }
      else{
	d*=a;
	if(i%2==0){
	  if(d)s--;
	  d=1;
	}
      }//printf("%c",w);
    }
    printf("%d\n",s);
  }
  return 0;
}
