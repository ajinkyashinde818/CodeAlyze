import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i=0; i<N; i++)
			A[i] = sc.nextInt();
		
		int ans = K;
		for(int i=0; i<N-1; i++) {
			ans = Math.min(ans, K-(A[i+1]-A[i]));
		}
		ans = Math.min(ans, A[N-1]-A[0]);

		System.out.println(ans);
		sc.close();
	}
}
