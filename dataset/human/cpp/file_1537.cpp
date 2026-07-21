#include <cstdio>
#include <vector>

std::vector<int> s[1024];

int main() {
	int n, k = 2;
	scanf("%d",&n);
	while (k * (k-1) < n<<1) k++;
	if (k * (k-1) != n<<1) {puts("No"); return 0;}
	for (int i = 1; i < k; i++)
		for (int j = 0; j < i; j++) {
			s[i].push_back(n);
			s[j].push_back(n);
			n--;
		}
	puts("Yes");
	printf("%d\n",k);
	for (int i = 0; i < k; i++) {
		printf("%lld ",s[i].size());
		for (int a : s[i])
			printf("%d ",a);
		putchar(10);
	}
	return 0;
}
