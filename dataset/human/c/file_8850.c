#include<stdio.h>

int main(){
  int h=0;
  int w=0;
  char grid[100][100];
  int i=0;
  int j=0;
  int dameflag=0;
  
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      scanf(" %c",&grid[i][j]);
    }

  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(grid[i][j] =='#'){
      	if(i+1<h && grid[i+1][j] == '#'){\
                  	continue;
      	}else if(i-1>=0 && grid[i-1][j] == '#'){
        	continue;
      	}else if(j+1<w && grid[i][j+1] == '#'){

        	continue;
        }else if(j-1>=0 && grid[i][j-1] == '#'){
        	continue;
      	}
        dameflag = 1;
      }else{
      }
    }
  }
  if(dameflag){
    printf("No");
  }else{
    printf("Yes");
  }
      
  return 0;
}
