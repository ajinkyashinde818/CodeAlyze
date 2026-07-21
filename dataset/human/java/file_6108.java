import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cnt = 0;
		int K = sc.nextInt();
		int S = sc.nextInt();
		for(int x = 0; x <= K; x++) {
			for(int y = 0; y <= K; y++) {
				if((S - x - y >= 0 )&&(S - x - y <= K)) {
					cnt++;
				}
			}
		}
		System.out.println(cnt);
	}
}
