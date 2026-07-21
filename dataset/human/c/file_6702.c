#include <stdio.h>
#include <string.h>

int n, m, a[11234], b[11234];
int my_friends[11234], their_friends[11234];
int ans = 0;
bool cancel = false;

int main(void) {
	while (true) {
		ans = 0;
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) { break; }
		for (int i = 0; i < m; ++i) { scanf("%d%d", &a[i], &b[i]); }

		memset(my_friends, -1, sizeof(my_friends));
		memset(their_friends, -1, sizeof(their_friends));
		my_friends[0] = 1, their_friends[0] = 1;
		for (int i = 0; i < m; ++i) {
			if (a[i] == 1) { my_friends[b[i] - 1] = b[i]; ans++; }
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i] == my_friends[j]) {
					for (int k = 0; k < n; ++k) {
						if (b[i] == my_friends[k] || b[i] == their_friends[k]) {
							cancel = true;
							break;
						}
					}
					if (cancel == false) { their_friends[b[i] - 1] = b[i]; ans++; }
					cancel = false;
				}
				else if (b[i] == my_friends[j]) {
					for (int k = 0; k < n; ++k) {
						if (a[i] == my_friends[k] || a[i] == their_friends[k]) {
							cancel = true;
							break;
						}
					}
					if (cancel == false) { their_friends[a[i] - 1] = a[i]; ans++; }
					cancel = false;
				}
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
