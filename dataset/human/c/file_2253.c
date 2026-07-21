#include<stdio.h>

int a[1000][1000];
int way,n;
//int call=0;

int square(int i, int j, int k){
  int x,y;

  //call++;
  if(i+k>n||j+k>n)
    return 0;

  for(x=i;x<i+k;x++){
    for(y=j;y<j+k;y++){
      if(!a[x][y])
	return 0;
    }
  }
  return k;
}

int main(){
  int i,j,k,c,max;

  for(;;){
    scanf("%d",&n);
    if(n==0)
      break;

    max=0;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	for(;;){
	  c=getchar();
	  if(c=='.'){
	    a[i][j]=1;
	    max=1;
	    break;
	  }
	  else if(c=='*'){
	    a[i][j]=0;
	    break;
	  }
	}
      }
    }
    
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	for(k=1;k<=n;k++){
	  int tmp=square(i,j,k);
	  if(max<tmp)
	    max=tmp;
	  else if(tmp==0)
	    break; 
	}
      }
    }
    printf("%d\n",max);
  }
  //printf("Call:%d\n",call);
  return 0;
}
