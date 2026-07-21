import java.util.Scanner;

/**
 * https://abc051.contest.atcoder.jp/tasks/abc051_b
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int S = sc.nextInt();
		sc.close();
		
		long ans = 0;
		for(int x=0; x<=K; x++){
			for(int y=0; y<=K; y++){
				int z = S-(x+y);
				if(z>=0 && z<=K) ans++;
			}
		}
		
		System.out.println(ans);

	}

}
