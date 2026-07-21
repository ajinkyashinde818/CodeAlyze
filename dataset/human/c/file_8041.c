#include <stdio.h>

#define Q_LENGTH 200000

void show_maze(int S[][1000], int height, int width, FILE *fp) {
  int h, w;

  for(h = 0; h < height; h++) {
    for(w = 0; w < width; w++) {
      if(S[h][w] == 0) {
        fputc(' ', fp);
        fputc(' ', fp);
      }else
        fprintf(fp, "%2d", S[h][w]);
    }
    fputc('\n', fp);
  }
}

int main(void){
  typedef struct{
	int h;
	int w;
  } point;
  
  int height, width;
  point start;
  point goal;
  int S[1000][1000];
  point queue[Q_LENGTH];
  int qhead = 0, qtale = 0;
  int h, w;
  point current;
  int warp = 0;
 
  scanf("%d%d", &height, &width);
  scanf("%d%d", &start.h, &start.w);
  scanf("%d%d", &goal.h, &goal.w);
  start.h--;
  start.w--;
  goal.h--;
  goal.w--;
  getchar();
  for(h = 0; h < height; h++){
    for(w = 0; w < width; w++){
      S[h][w] = (getchar() == '#');
    }
    getchar();
  }
  
  queue[0] = start;
  qtale = 1;
  S[start.h][start.w] = 1;
  	
  while(qhead != qtale || current.h != goal.h || current.w != goal.w){
    point tmp[24] = {{0,1}, {1,0}, {0,-1}, {-1, 0}, {2, 2}, {2, 1}, {2, 0}, {2, -1}, {2, -2},{1, 2}, {1, 1}, {1, -1}, {1, -2}, {0, 2}, {0, -2}, {-1, 2}, {-1, 1}, {-1, -1}, {-1, -2}, {-2, 2}, {-2, 1}, {-2, 0}, {-2, -1}, {-2, -2}};
	int i = 0;
    current = queue[qhead];
	qhead = (qhead + 1) %Q_LENGTH;

	for(; i < 4; i++){
      point pt = {current.h + tmp[i].h, current.w + tmp[i].w};

      if(pt.h < 0 || pt.h >= height || pt.w < 0 || pt.w >= width)
        continue;

	  if((!S[pt.h][pt.w]) || S[pt.h][pt.w] > S[current.h][current.w]){
		S[pt.h][pt.w] = S[current.h][current.w];
		queue[qtale] = pt;
		qtale = (qtale + 1)%Q_LENGTH;
	  }
	}

	for(; i < 24; i++){
	  point pt = {current.h + tmp[i].h, current.w + tmp[i].w};
    
      if(pt.h < 0 || pt.h >= height || pt.w < 0 || pt.w >= width)
        continue;

	  if((!S[pt.h][pt.w]) || S[pt.h][pt.w] > S[current.h][current.w]+1){
		S[pt.h][pt.w] = S[current.h][current.w] + 1;
		queue[qtale] = pt;
		qtale = (qtale + 1)%Q_LENGTH;
	  }
	}
    if(qhead == qtale){
      if(S[goal.h][goal.w]) {
        break;
      } else {
        printf("-1\n");
        return 0;
      }
    }
  }

  printf("%d\n", S[goal.h][goal.w]-1);
  
  return 0;
}
