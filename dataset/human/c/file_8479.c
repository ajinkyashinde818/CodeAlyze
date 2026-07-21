#include<stdio.h>
int main(){
  int a[11][5];
  int h,i,j,k,c,po,score,sw,sw2;
  while(1){
    score=0;
    sw=0;
    sw2=0;
    po=0;
    c=0;

    scanf("%d",&h);
    if(h==0)break;
    for(i=0;i<h;i++){
      for(j=0;j<5;j++){
	scanf("%d",&a[i][j]);
      }
    }
    //  printf("check0\n");
    while(1){
      sw=score;
      //del
      for(i=0;i<h;i++){
	for(j=0;j<3;j++){
	  c=1;
	  po=a[i][j];
	  for(k=1;j+k<5;k++){
	    if(a[i][j+k]==po){
	      c++;
	    }
	    else break;
	  }
	  if(c>=3){
	    for(k=0;k<c;k++){
	      score+=a[i][j+k];
	      a[i][j+k]=0;
	    }
	  }
	}
      }
      if(sw==score)break;
      //del end
      //  printf("check1\n");
      //fall
      while(1){
	sw2=0;
	if(h!=0){
	  for(i=h-2;i>=0;i--){
	    for(j=0;j<5;j++){
	      if(a[i][j]!=0&&a[i+1][j]==0){
		a[i+1][j]=a[i][j];
		a[i][j]=0;
		sw2=1;
	      }
	    }
	  }
	}
	if(sw2==0)break;
      }
      //fall end
      //  printf("check2\n");
    }
    printf("%d\n",score);
  }
  return 0;
}
