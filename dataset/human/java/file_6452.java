import java.util.*;
public class Main {
	public static void main(String[] args) {
		int cnt = 0;
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int S = sc.nextInt();
		for(int i = 0;i <= K;i ++) {
			for(int j = 0;j <= K;j ++) {
				int k = S - i - j;
				if(0 <= k && k <= K) cnt ++;
			}
		}
		System.out.println(cnt);
	}
}
