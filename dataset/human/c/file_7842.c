#include<stdio.h>

//macro
#define SIZE 1000000

//typedef
typedef struct{
	int posx[SIZE];
	int posy[SIZE];
	int turn[SIZE];
	int save;
	int load;
} queue_t;

//global
queue_t q;
int x,y,n;
int inix,iniy,initurn;
char field[1000][1000]={};
int map[1000][1000]={};
char cheese;
int answer=0;

void input(void){
	int loop1,loop2;
	char temp;
	scanf("%d%d%d",&y,&x,&n);
	for(loop1=0;loop1<y;loop1++){
		for(loop2=0;loop2<x;loop2++){
			scanf("%c",&temp);
			if(temp!='\n'){
				field[loop2][loop1]=temp;
			}
			else{
				loop2--;
			}
			if(field[loop2][loop1]=='S'){
				inix=loop2;
				iniy=loop1;
			}
		}
	}
}

void initialize(int inix,int iniy){
	int loop1,loop2;
	q.posx[0]=inix;
	q.posy[0]=iniy;
	q.turn[0]=0;
	for(loop1=1;loop1<SIZE;loop1++){
		q.posx[loop1]=0;
		q.posy[loop1]=0;
		q.turn[loop1]=0;
	}
	for(loop1=0;loop1<1000;loop1++){
		for(loop2=0;loop2<1000;loop2++){
			map[loop1][loop2]=0;
		}
	}
	map[inix][iniy]++;
	q.save=1;
	q.load=0;
	//printf("initialized: %d %d %d",q.posx[q.load],q.posy[q.load],q.turn[q.load]);
}
int search(int cheesenum){
	sprintf(&cheese,"%d",cheesenum);
	//printf("mouse: I'm going to eat cheese No.%c\n",cheese);
	while(field[q.posx[q.load]][q.posy[q.load]]!=cheese){
		while(q.turn[q.load]>1000000){
			q.load++;
		}
		if(q.posx[q.load]+1<x && field[q.posx[q.load]+1][q.posy[q.load]]!='X' && map[q.posx[q.load]+1][q.posy[q.load]]==0){
			map[q.posx[q.load]+1][q.posy[q.load]]++;
			q.posx[q.save]=q.posx[q.load]+1;
			q.posy[q.save]=q.posy[q.load];
			q.turn[q.save]=q.turn[q.load]+1;
			//printf("I'm at %d %d, time is %d\n",q.posx[q.save],q.posy[q.save],q.turn[q.save]);
			q.save++;
			
		}
		if(q.posx[q.load]-1>=0 && field[q.posx[q.load]-1][q.posy[q.load]]!='X' && map[q.posx[q.load]-1][q.posy[q.load]]==0){
			map[q.posx[q.load]-1][q.posy[q.load]]++;
			q.posx[q.save]=q.posx[q.load]-1;
			q.posy[q.save]=q.posy[q.load];
			q.turn[q.save]=q.turn[q.load]+1;
			//printf("I'm at %d %d, time is %d\n",q.posx[q.save],q.posy[q.save],q.turn[q.save]);
			q.save++;
		}
		if(q.posy[q.load]+1<y && field[q.posx[q.load]][q.posy[q.load]+1]!='X'  && map[q.posx[q.load]][q.posy[q.load]+1]==0){
			map[q.posx[q.load]][q.posy[q.load]+1]++;
			q.posx[q.save]=q.posx[q.load];
			q.posy[q.save]=q.posy[q.load]+1;
			q.turn[q.save]=q.turn[q.load]+1;
			//printf("I'm at %d %d, time is %d\n",q.posx[q.save],q.posy[q.save],q.turn[q.save]);
			q.save++;
		}
		if(q.posy[q.load]-1>=0 && field[q.posx[q.load]][q.posy[q.load]-1]!='X' && map[q.posx[q.load]][q.posy[q.load]-1]==0){
			map[q.posx[q.load]][q.posy[q.load]-1]++;
			q.posx[q.save]=q.posx[q.load];
			q.posy[q.save]=q.posy[q.load]-1;
			q.turn[q.save]=q.turn[q.load]+1;
			//printf("I'm at %d %d, time is %d\n",q.posx[q.save],q.posy[q.save],q.turn[q.save]);
			q.save++;
		}
		//printf("------\n");
		q.load++;
	}
	inix=q.posx[q.load];
	iniy=q.posy[q.load];
	return q.turn[q.load];
}

int main(void){
	int loop1;
	input();
	for(loop1=1;loop1<=n;loop1++){
		initialize(inix,iniy);
		answer+=search(loop1);
	}
	printf("%d\n",answer);
	
	return 0;
}
