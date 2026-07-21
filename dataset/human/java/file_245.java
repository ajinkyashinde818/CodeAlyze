import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A[] = new int[N];
		int cnt = 0;
		int min = Integer.MAX_VALUE;
		long sum = 0;
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
			if(A[i] < 0) {
				cnt++;
			}
			min = Math.min(Math.abs(min), Math.abs(A[i]));
			sum += Math.abs(A[i]);
		}
		
		if(cnt % 2 == 0) {
			System.out.println(sum);
		} else {
			System.out.println(sum - Math.abs(min) * 2);
		}
	}
}
