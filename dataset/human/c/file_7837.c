#include <stdio.h>
#include <stdlib.h>

int head,u , tail;
int q[1000001];
int map[1001][1001];
int dis[1001][1001];
int fac[10];
int sum = 0;
int w,h,n;

void enque(int x) {
  q[tail] = x;
  if(tail == 1000000) tail = -1;
  tail++;

}

int deque() {
  int x = q[head];

  if(head == 1000000) head = -1;
  head ++;
  return x;

}

int bfs(int s,int g) {
  int i,j;
  int dx[4] = {0,-1,0,1};
  int dy[4] = {1,0,-1,0};
  int nx,ny;
  head = tail = 0;

  enque(s);

  for(j = 0;j<h;j++) {
    for(i =0;i<w;i++) {
      dis[j][i] = -1;
    }
  }

  dis[s/w][s%w] = 0;
 
  while(tail != head) {

    u = deque(); 
     
    for(i=0;i<4;i++) {

      nx = u/w + dx[i];
      ny = u%w + dy[i];
      if(nx >=0 && ny >= 0 && nx <h && ny < w) {
	if(map[nx][ny] != -2 && dis[nx][ny] == -1) {
	  dis[nx][ny] = dis[u/w][u%w]+1;
	  enque(nx*w+ny);
	}
      }
    }
  }
  // printf("dis[%d][%d] = %d\n",g/w,g%w,dis[g/w][g%w]);
  return dis[g/w][g%w];
  
  
	 
}
       

int main() {
 
  int i,j,k;
  char ch[1002];
  int start;

  scanf("%d %d %d",&h,&w,&n);


  k = 0;
  for(i=0;i<h;i++) {
 scanf("%s",ch);
    for(j=0;j<w;j++) {
     
      if(ch[j] == 'S') {
	start = i*w+j;
	map[i][j] = 0;
      }
      else if(ch[j] == '.') map[i][j] = -1;
      else if(ch[j] == 'X') map[i][j] = -2;
      else {
	map[i][j] = ch[j] - '0';
	fac[ch[j]-'0'] = i*w+j;
      }
    }
  }

  /* for(j=0;j<h;j++) {
    for(i=0;i<w;i++) {
      printf("%d ",map[j][i]);
    }
    printf("\n");
    }*/

  for(i=1;i<=n;i++) {

    sum += bfs(start,fac[i]);
    start = fac[i];

  }

  printf("%d\n",sum);

  return 0;

}
