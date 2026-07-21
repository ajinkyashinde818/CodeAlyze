#include <stdio.h>

typedef struct{
  int x,y,t;
}Point;

Point Q[10000];
int head,tail;
char map[1000][1000];
Point p,next;
int h,w,n;
int visited[1000][1000];
  

void enqueue(Point n){
  Q[tail] = n;
  tail = (tail+1)%10000;
}

Point  dequeue(){
  Point re;
  re = Q[head];
  head = (head+1)%10000;
  return re;
}


int bfs(Point start,char end){
  int i,j;
  for(i=0;i<h;i++)
    for(j=0;j<w;j++)
      visited[i][j]=0;

  head = 0;
  tail = 0;
  enqueue(start);
  while(head != tail){
    p = dequeue();

    if(map[p.x][p.y] == end) break;
    else  p.t++;

    if(p.x+1 < h &&  map[p.x+1][p.y] != 'X' && visited[p.x+1][p.y]==0){
      next=p;
      next.x++;
      enqueue(next);
      visited[next.x][next.y]=1;
    }
    if(p.x-1 >= 0 && map[p.x-1][p.y] != 'X' && visited[p.x-1][p.y]==0){
      next=p;
      next.x--;
      enqueue(next);
      visited[next.x][next.y]=1;
    }
    if(p.y+1 < w && map[p.x][p.y+1] != 'X' && visited[p.x][p.y+1]==0){
      next=p;
      next.y++;
      enqueue(next);
      visited[next.x][next.y]=1;
    }
    if(p.y-1 >= 0 && map[p.x][p.y-1] != 'X' && visited[p.x][p.y-1]==0){
      next=p;
      next.y--;
      enqueue(next);
      visited[next.x][next.y]=1;
    }
  }
  return p.t;
}
  

int main (){
  int i,j,k;
  int time;
  char hp,str[2000];
  Point start;

  scanf("%d %d %d",&h,&w,&n);
  for(i=0;i<h;i++){
    scanf("%s",str);
    for(j=0;j<w;j++){
      map[i][j] = str[j];
      if(map[i][j] == 'S'){
	start.x = i;
	start.y = j;
      }
    }
  }
  /*
  printf("\n");
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      printf("%c",map[i][j]);
    }
    printf("\n");
  }
  */
  hp=1;
  time = 0;

  while(hp<=n){
    start.t=0;
    time += bfs(start,'0'+hp);
    hp++;
    start = p;
  }
  printf("%d\n",time);

  return 0;
}
