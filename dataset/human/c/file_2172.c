#include <stdio.h>
#include <string.h>

#define CAPA 500001
#define MID  200000 

void inputAndCalc();
	void checkAndSet();
		void addChar();
void output();

char s[CAPA],				//head - 200K, tailMax + 200K
	 c;
char *pa = &s[MID], *pb;	//points head or tail of s
int  q, t, f;
bool bReverse = false, bHead = true;

int main() {
	inputAndCalc();
	output();
	return 0;
}

void inputAndCalc() {
	scanf("%s", pa);				//put head in the middle
	pb = &pa[strlen(pa) - 1];		//needs -1 to point tail
	scanf("%d", &q);
	checkAndSet();					//check queries and get ans
	return;
}

void checkAndSet() {
	for (int i = 0; i < q; i++) {
		scanf("%d", &t);
		if (t == 1)
			bReverse = !bReverse;	//changes flag
		else {
			scanf("%d %c", &f, &c);
			bHead = f % 2;			// 1 -> head, 2 -> tail
			addChar();				//add char to s
		}
	}
}

void addChar() {
	if (!(!bReverse ^ bHead))		//tip: draw Venn diagram
		*(--pa) = c;				//move -> sustitute
	else
		*(++pb) = c;				//mo(ry
	return;
}

void output() {
	if (!bReverse)
		puts(pa);
	else
		while (pb >= pa) {
			putchar(*pb--);			//put -> move
		}
	putchar('\n');
	return;
}
