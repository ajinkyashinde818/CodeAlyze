import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int S = sc.nextInt();
		sc.close();
		
		int ans = 0;
		for(int i = 0;i <= K;++i) {
			for(int j = 0;j <= K;++j) {
				int res = S - i - j;
				if(0 <= res && res <= K)
					++ans;
			}
		}
		System.out.println(ans);
	}
}
