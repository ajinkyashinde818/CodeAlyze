import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		long ans = 0;
		int minus = 0;
		int min = Integer.MAX_VALUE;
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
			ans += Math.abs(A[i]);
			if(A[i] < 0)
				minus++;
			min = Math.min(min, Math.abs(A[i]));
		}
		if(minus % 2 == 1)
			ans -= min*2;
		System.out.println(ans);
	}

}
