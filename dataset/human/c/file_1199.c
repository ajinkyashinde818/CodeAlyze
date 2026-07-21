#include<stdio.h>
#include<string.h>

int main(void) {
	char s[101], t[101];
	
	scanf("%s", s);
	scanf("%s", t);

	int s_len = strlen(s);
	char s_res[101];
	for (int i=0; i<s_len; i++) {
		int min_idx = 0;
		for (int j=1; j<s_len; j++) {
			if (s[j] < s[min_idx]) {
				min_idx = j;
			}
		}

		s_res[i] = s[min_idx];
		s[min_idx] = 'z';
	}

	s_res[s_len] = '\0';

	int t_len = strlen(t);
	char t_res[101];
	for (int i=0; i<t_len; i++) {
		char max_idx = 0;
		for (int j=1; j<t_len; j++) {
			if (t[j] > t[max_idx]) {
				max_idx = j;
			}
		}

		t_res[i] = t[max_idx];
		t[max_idx] = 'a';
	}

	t_res[t_len] = '\0';

	//printf("%s\n", s_res);
	//printf("%s\n", t_res);
	if (strcmp(s_res, t_res) < 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}
