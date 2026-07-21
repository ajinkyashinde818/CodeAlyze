#include <stdio.h>
#include <string.h>

int isaki(char c) {
	if(c=='.' || c=='X')return 1; else return 0;
}

int main(void) {
	int width,height;
	char map[32][32];
	char p_map[32][32];
	char np_map[32][32];
	int x,y;
	int c_time;
	int people_exist;
	while(1) {
		scanf("%d%d",&width,&height);
		if(width==0 && height==0)break;
		memset(map,'#',sizeof(map));
		for(y=1;y<=height;y++) {
			scanf("%s",&map[y][1]);
			map[y][width+1]='#';
		}
		memset(p_map,0,sizeof(p_map));
		for(y=1;y<=height;y++) {
			for(x=1;x<=width;x++) {
				if(map[y][x]=='E' || map[y][x]=='N' ||
						map[y][x]=='W' || map[y][x]=='S') {
					p_map[y][x]=map[y][x];
					map[y][x]='.';
				}
			}
		}
		for(c_time=0;c_time<=180;c_time++) {
			people_exist=0;
			for(y=1;y<=height;y++) {
				for(x=1;x<=width;x++) {
					switch(p_map[y][x]) {
						case 'E':
							people_exist=1;
							if(isaki(map[y+1][x]) && p_map[y+1][x]==0) {
								p_map[y][x]='S';
							} else if(isaki(map[y][x+1]) && p_map[y][x+1]==0) {
								p_map[y][x]='E';
							} else if(isaki(map[y-1][x]) && p_map[y-1][x]==0) {
								p_map[y][x]='N';
							} else if(isaki(map[y][x-1]) && p_map[y][x-1]==0) {
								p_map[y][x]='W';
							}
							break;
						case 'N':
							people_exist=1;
							if(isaki(map[y][x+1]) && p_map[y][x+1]==0) {
								p_map[y][x]='E';
							} else if(isaki(map[y-1][x]) && p_map[y-1][x]==0) {
								p_map[y][x]='N';
							} else if(isaki(map[y][x-1]) && p_map[y][x-1]==0) {
								p_map[y][x]='W';
							} else if(isaki(map[y+1][x]) && p_map[y+1][x]==0) {
								p_map[y][x]='S';
							}
							break;
						case 'W':
							people_exist=1;
							if(isaki(map[y-1][x]) && p_map[y-1][x]==0) {
								p_map[y][x]='N';
							} else if(isaki(map[y][x-1]) && p_map[y][x-1]==0) {
								p_map[y][x]='W';
							} else if(isaki(map[y+1][x]) && p_map[y+1][x]==0) {
								p_map[y][x]='S';
							} else if(isaki(map[y][x+1]) && p_map[y][x+1]==0) {
								p_map[y][x]='E';
							}
							break;
						case 'S':
							people_exist=1;
							if(isaki(map[y][x-1]) && p_map[y][x-1]==0) {
								p_map[y][x]='W';
							} else if(isaki(map[y+1][x]) && p_map[y+1][x]==0) {
								p_map[y][x]='S';
							} else if(isaki(map[y][x+1]) && p_map[y][x+1]==0) {
								p_map[y][x]='E';
							} else if(isaki(map[y-1][x]) && p_map[y-1][x]==0) {
								p_map[y][x]='N';
							}
							break;
					}
				}
			}
			if(!people_exist)break;
			memcpy(np_map,p_map,sizeof(p_map));
			for(y=1;y<=height;y++) {
				for(x=1;x<=width;x++) {
					if(isaki(map[y][x]) && p_map[y][x]==0) {
						if(p_map[y][x+1]=='W') {
							np_map[y][x]='W';
							np_map[y][x+1]=0;
						} else if(p_map[y-1][x]=='S') {
							np_map[y][x]='S';
							np_map[y-1][x]=0;
						} else if(p_map[y][x-1]=='E') {
							np_map[y][x]='E';
							np_map[y][x-1]=0;
						} else if(p_map[y+1][x]=='N') {
							np_map[y][x]='N';
							np_map[y+1][x]=0;
						}
						if(map[y][x]=='X')np_map[y][x]=0;
					}
				}
			}
			memcpy(p_map,np_map,sizeof(np_map));
		}
		if(c_time>180)puts("NA"); else printf("%d\n",c_time);
	}
	return 0;
}
