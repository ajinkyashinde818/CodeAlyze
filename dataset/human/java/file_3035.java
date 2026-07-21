import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int a[] = new int[M];
		int b[] = new int[M];
		boolean flag[] = new boolean[N];
		Arrays.fill(flag, false);
		for(int i = 0; i < M; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			if(a[i] == N) {
				flag[b[i]] = true;
			}
			if(b[i] == N) {
				flag[a[i]] = true;
			}
		}
		
		for(int i = 0; i < M; i++) {
			if(a[i] == 1 && flag[b[i]]) {
				System.out.println("POSSIBLE");
				return;
			}
			if(b[i] == 1 && flag[a[i]]) {
				System.out.println("POSSIBLE");
				return;
			}
		}
		System.out.println("IMPOSSIBLE");
	}
}
