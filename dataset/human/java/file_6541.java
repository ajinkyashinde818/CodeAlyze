import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String[] tmpString = sc.nextLine().split(" ");
		int K = Integer.parseInt(tmpString[0]);
		int S = Integer.parseInt(tmpString[1]);
		
		int count = 0;
		for (int i = 0; i <= K; i++) {
			for (int j = 0; j <= K; j++) {
				int total = S - i - j;
				if (total >= 0 && total <= K) count++;
			}
		}
		
		System.out.println(count);
	}
}
