#include<stdio.h>
#include<stdbool.h>

int main(int argc, char *argv[]){
  int h, w;
  scanf("%d %d", &h, &w);
  //printf("h=%d, w=%d\n", h, w);

  char s[h][w];
  for(int i=0; i<h; i++){
    scanf("%s", s[i]);
  }

  /*
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      printf("%c", s[i][j]);
    }
    printf("\n");
  }
  */

  bool ok = true;
  char mark = '#';
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(s[i][j] == '#'){
        // top left
        //if(i>0     && j>0     && s[i-1][j-1] == mark){}

        // top center
        if(i>0                && s[i-1][j]   == mark) continue;

        // top right
        //if(i>0     && j<(w-1) && s[i-1][j+1] == mark){}

        // middle left
        if(           j>0     && s[i][j-1]   == mark) continue;

        // middle center

        // middle right
        if(           j<(w-1) && s[i][j+1]   == mark) continue;

        // bottom left
        //if(i<(h-1) && j>0     && s[i+1][j-1] == mark){}

        // bottom center
        if(i<(h-1)            && s[i+1][j]   == mark) continue;

        // bottom right
        //if(i<(h-1) && j<(w-1) && s[i+1][j+1] == mark){}

        ok = false;
        break;
      }
      if(!ok) break;
    }
  }

  if(ok){
    printf("Yes\n");
  }else{
    printf("No\n");
  }


  return 0;
}
