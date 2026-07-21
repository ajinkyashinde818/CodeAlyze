#include<stdio.h>

int partition(int a [], int l, int r) {
    int i = l - 1;
    int j = r;
    int temp;
 
    int pivot = a[r];
 
    while (1) {
        while (a[++i] < pivot) ;
        while (i < --j && pivot < a[j]) ;

        if (i >= j) break;
 
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    temp = a[i];
    a[i] = a[r];
    a[r] = temp;
    return i;
}

void quickSort(int a[], int l, int r) {
    int v;
    if (l >= r) {
        return;
    }
    v = partition(a, l, r);
    quickSort(a, l, v - 1);
    quickSort(a, v + 1, r);
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int a[N], b[N], s, t, k = 0, l = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &t);
		if (s == 1) {
			a[k] = t;
			k++;
		} else if (t == N) {
			b[l] = s;
			l++;
		}
	}
	if (k == 0 || l == 0) {
		printf("IMPOSSIBLE");
	    return 0;
	} 
	quickSort(a, 0, k - 1);
	quickSort(b, 0, l - 1);
	s = 0, t = 0;
	while (1) {
	    if (s > k || t > l) {
	    	printf("IMPOSSIBLE");
	    	return 0;
	    }
		if (a[s] == b[t]) {
			printf("POSSIBLE");
			return 0;
		} else if (a[s] > b[t]) {
			t++;
		} else {
			s++;
		}
	}
}
