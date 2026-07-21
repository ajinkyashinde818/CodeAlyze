#include<cstdio>
#include<cstring>
using namespace std;

unsigned long long grundy(unsigned long long x) {
	return ((x+1)^x) & (x+1);
}

class Trie {
public:
	Trie *zero;
	Trie *one;
	Trie() {
		zero = NULL;
		one = NULL;
	}
};
int ind = 0;
Trie buf[100000];

void AddString(Trie *t, char s[], int len, int i = 0) {
	if(i >= len) return;
	if(s[i] == '0') {
		if(t->zero == NULL) t->zero = &buf[ind++];
		AddString(t->zero, s, len, i+1);
	} else {
		if(t->one == NULL) t->one = &buf[ind++];
		AddString(t->one, s, len, i+1);
	}
}
unsigned long long Grundy(Trie *t, unsigned long long l) {
	unsigned long long g = 0;
	if(t->zero == NULL && t->one == NULL) return 0;
	g ^= t->zero == NULL ? grundy(l-1) : Grundy(t->zero, l-1);
	g ^= t->one == NULL ? grundy(l-1) : Grundy(t->one, l-1);
	return g;
}

int main() {
	int n;
	unsigned long long l;
	char s[100000+1];
	Trie t;
	scanf("%d %llu", &n, &l);
	for(int i=0;i<n;i++) {
		scanf("%100000s", s);
		AddString(&t, s, strlen(s));
	}
	printf("%s\n", Grundy(&t, l) != 0 ? "Alice" : "Bob");
	return 0;
}
