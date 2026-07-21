import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int[] a = new int[n];
	int min = Integer.MAX_VALUE;
	int cnt = 0;
	long total = 0;
	for(int i = 0; i<n; i++) {
	    a[i] = sc.nextInt();
	    min = Math.min(Math.abs(a[i]),min);
	    if(a[i]<0)cnt++;
	    total += Math.abs(a[i]);
	}
	if(cnt % 2 == 0) {
	    System.out.println(total);
	}else {
	    System.out.println(total-min*2);
	}
    }
}
