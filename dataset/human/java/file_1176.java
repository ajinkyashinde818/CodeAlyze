import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	long[] a = new long[n];
	long[] asum = new long[n];
	long[] bsum = new long[n+1];

	for(int i = 0; i<n; i++) {
	    a[i] = sc.nextInt();
	}

	for(int i = 0; i<n; i++) {
	    if(i == 0) {
		asum[i] = a[i];
		continue;
	    }
	    asum[i] = a[i] + asum[i-1];
	}

	for(int i = n; i>=0; i--) {
            if(i == n) {
		bsum[i] = 0;
		continue;
            }
            bsum[i] = a[i] + bsum[i+1];
        }

	long min = Long.MAX_VALUE;
	for(int i = 0; i<n-1; i++) {
	    min = Math.min(min, Math.abs(asum[i]-bsum[i+1]));
	}
	System.out.println(min);
    }
}
