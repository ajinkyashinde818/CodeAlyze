#include <stdio.h>
#include <string.h>

#define MAX_KETA 501

/*
[Êu][±êÜÅÌðMÅÁ½]è][OÌ]
[OÍñÂO©çÁ©¸­©][±êÜÅÌÍBÆêvµÄ¢é©]
OÍñÂO©çÁ©¸­©ÉÂ¢Ä
0FOÍ0ÈÌÅÖWÈ¢
1FÁ
2F¸­ 
*/
int memo[MAX_KETA][500][10][3][2];

int waru_amari(const char* a,int b) {
	int current=0;
	int i;
	for(i=0;a[i]!=0;i++) {
		current=(current*10+(a[i]-'0'))%b;
	}
	return current;
}

int is_zigzag(const char* a) {
	int i;
	int len;
	len=strlen(a);
	if(len==1)return 1;
	if(len==2) {
		if(a[0]!=a[1])return 1; else return 0;
	}
	for(i=2;i<len;i++) {
		if((a[i-2]-a[i-1])*(a[i-1]-a[i])>=0)return 0;
	}
	return 1;
}

int calc_zigzag(const char* max,int waru,int now,int amari,
		int pnum,int pisup,int ismax);

int main(void) {
	char input_A[MAX_KETA+1];
	char input_B[MAX_KETA+1];
	int waru_kazu;
	int result_A;
	int result_B;
	int result;
	scanf("%s",input_A);
	scanf("%s",input_B);
	scanf("%d",&waru_kazu);
	result_A=calc_zigzag(input_A,waru_kazu,0,0,0,0,1)+
		calc_zigzag(input_A,waru_kazu,0,0,0,1,1);
	memset(memo,0,sizeof(memo));
	result_B=calc_zigzag(input_B,waru_kazu,0,0,0,0,1)+
		calc_zigzag(input_B,waru_kazu,0,0,0,1,1);
	result=result_B-result_A;
	if(is_zigzag(input_A) && waru_amari(input_A,waru_kazu)==0) {
		result++;
	}
	if(result<0)result+=10000;
	printf("%d\n",result);
	return 0;
}

/*
waruF Üèðæé½ßÉé 
nowF»ÝÌÊu
amariFOÌÜÅÌ Üè 
pnumFOÌ
pisupFOÍÁµÄ¢é© 
*/
int calc_zigzag(const char* max,int waru,int now,int amari,
		int pnum,int pisup,int ismax) {
	int i;
	int start,end;
	int result=0;
	int next_pisup;
	if(max[now]==0) {
		if(amari==0)return 1; else return 0;
	}
	if(memo[now][amari][pnum][pisup][ismax]>0) {
		return memo[now][amari][pnum][pisup][ismax]-1;
	}
	if(pisup==1) {
		/*¸­³¹é*/
		start=0;
		end=pnum-1;
	} else if(pisup==2) {
		/*Á³¹é*/
		start=pnum+1;
		end=9;
	} else {
		/*OÍ0*/
		start=0;
		end=9;
	}
	if(ismax && end>max[now]-'0')end=max[now]-'0';
	for(i=start;i<=end;i++) {
		if(pisup==0) {
			if(pnum==0)next_pisup=0;
			else if(i<pnum)next_pisup=2;
			else if(i>pnum)next_pisup=1;
			else continue;
		} else {
			if(pisup==1)next_pisup=2; else next_pisup=1;
		}
		result+=calc_zigzag(max,waru,now+1,(amari*10+i)%waru,
			i,next_pisup,(ismax && i==max[now]-'0')?1:0);
	}
	result%=10000;
	memo[now][amari][pnum][pisup][ismax]=result+1;
	return result;
}
