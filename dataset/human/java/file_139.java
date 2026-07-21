import java.util.*;

public class Main {
	Scanner sc = new Scanner(System.in);

	void doIt() {
		int n = sc.nextInt();
		int a[] = new int[n];
		long sum = 0l;
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			int num = sc.nextInt();
			a[i] = Math.abs(num);
			sum += a[i];
			if(num < 0)cnt++;
		}
		Arrays.sort(a);
		if(cnt % 2 != 0) {
			sum -= a[0] * 2;
		}
		System.out.println(sum);
	}




	public static void main(String[] args) {
		new Main().doIt();
	}
}
