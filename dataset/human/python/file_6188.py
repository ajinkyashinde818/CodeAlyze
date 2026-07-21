import std.stdio;

int[111] book;
int n, m;

void main(){
	int left, right, mid;
	while (readf("%d %d\n", &m, &n), [m,n] != [0, 0]) {
		foreach (i; 0..n) readf("%d\n", &book[i]);
		left = 0;
		right = 1500000;
		while (left < right - 1) {
			mid = (left + right) / 2;
			if (countShelf(mid) > m) left = mid; 
			else right = mid;
		}
		writeln(right);
	}
}

int countShelf(int mid){
	int sum = 0;
	int res = 1;
	foreach (i; 0..n) {
		if (book[i] > mid) return 9999999;
		if (sum + book[i] > mid) {
			res++;
			sum = 0;
		}
		sum += book[i];
	}
	return res;
}
