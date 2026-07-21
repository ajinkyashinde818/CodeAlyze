import java.util.*;

public class Main {
	static class Sushi {
		long x;
		long v;
		public Sushi(long x, long v) {
			this.x = x;
			this.v = v;
		}
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		long C = sc.nextLong();

		Sushi[] s = new Sushi[N];
		for(int i=0; i<N; i++)
			s[i] = new Sushi(sc.nextLong(), sc.nextLong());
		
		long ans = solve(s, C);
		Arrays.sort(s, new Comparator<Sushi>() {
			public int compare(Sushi s1, Sushi s2) {
				return - Long.compare(s1.x, s2.x);
			}
		});
		for(int i=0; i<N; i++)
			s[i].x = C-s[i].x;
		
		ans = Math.max(ans, solve(s, C));
		
		System.out.println(ans);
		sc.close();
	}
	
	static long solve(Sushi[] s, long C) {
		int N = s.length;
		long[] cwmax = new long[N+1];
		long sum = 0;
		for(int i=0; i<N; i++) {
			sum += s[i].v;
			cwmax[i+1] = Math.max(cwmax[i], sum - s[i].x);
		}
		
		long max = cwmax[N];
		sum = 0;
		for(int i=N-1; i>=0; i--) {
			sum += s[i].v;
			max = Math.max(max, sum - (C-s[i].x)*2 + cwmax[i]);
		}
		
		return max;
	}
}
