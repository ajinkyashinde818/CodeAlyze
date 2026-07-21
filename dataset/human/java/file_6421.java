import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int K = scan.nextInt();
		int S = scan.nextInt();
		int ans = 0;
		int z = 0;
		for(int x = 0; x <= K; x++) {
			for(int y = 0; y <= K; y++) {
				z = S - x - y;
				if(0 <= z && z <= K) {
					ans++;
				}
			}
		}
		System.out.println(ans);
		scan.close();
	}

}
