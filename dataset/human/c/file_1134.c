#include <stdio.h>

void Sort_big(char* c, char *c_s);
void Sort_small(char* c, char *c_s);
int Hikaku(char *s_s,char *t_s);

int main(void){
	char s[100] = {0};
	char t[100] = {0};
	char s_s[100] = {0};
	char t_s[100] = {0};

	scanf("%s%s",&s,&t);

	Sort_small(&s[0], &s_s[0]);
	Sort_big(&t[0], &t_s[0]);

//	printf("s' : %s\nt' : %s\n",s_s,t_s);
//	printf("s' < t' = ");

	if(Hikaku(s_s,t_s) == 0)	printf("Yes");
	else	printf("No");
	return 0;
}


//	大きい順にソート
void Sort_big(char *c , char *c_s){
	int i,j;
	char max_c = 0;
	int max_i = 0;

	for(j = 0; j < 100; j++){
		for(i = 0; i < 100; i++){
			if(max_c < c[i]){
				max_c = c[i];
				max_i = i;
			}
	}
	if(max_c == 0)	break;
		c_s[j] = max_c;
		c[max_i] = 0;
		max_c = 0;
	}

}

//	小さい順にソート
void Sort_small(char *c , char *c_s){
	int i,j;
	char max_c = 0;
	char bf_c_s[100];
	int max_i = 0;

	for(j = 0; j < 100; j++){
		for(i = 0; i < 100; i++){
			if(max_c < c[i]){
				max_c = c[i];
				max_i = i;
			}
	}
	if(max_c == 0)	break;
		bf_c_s[j] = max_c;
		c[max_i] = 0;
		max_c = 0;
	}

	for(i = 0; j >= 0; i++){
		j--;
		c_s[i] = bf_c_s[j];
	}
	

}


//	s' < t' なら0返す s'> t'なら1返す
int Hikaku(char *s_s,char *t_s){
	int i;
	for(i = 0; i < 100; i++){
		if(t_s[i] != s_s[i]) break;
		if(i == 99) return 1;
	}
	for(i = 0; i < 100; i++){
		if(s_s[i] != EOF && t_s[i] == EOF)	return 0;
		if(t_s[i] < s_s[i])	return 1;
		if(t_s[i] > s_s[i]) return 0;
	}

	return -1;
}
