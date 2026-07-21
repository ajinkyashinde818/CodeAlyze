#include <stdio.h>

int around[4][2] = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0}
};

int main(){
  int h, w;  scanf("%d %d", &h, &w);
  char field[52][52];
  for(int i=0; i<h; i++)
    scanf("%s", field[i]);

  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(field[i][j] == '#'){
	int flag = 1;
	for(int a=0; a<4; a++){
	  int ai = i + around[a][0];
	  int aj = j + around[a][1];
	  if(ai < 0 || ai >= h || aj < 0 || aj >= w)  continue;
	  if(field[ai][aj] == '#')  flag = 0;
	}
	if(flag){
	  printf("No\n");
	  return 0;
	}
      }
    }
  }
  printf("Yes\n");
  return 0;
}
