import java.util.Scanner;

public class Main {
	/**
	 * Sum of Three Integers
	 * @param 2 ≦ K ≦ 2500
	 * @param 0 ≦ S ≦ 3K
	 * @param 0 ≦ X,Y,Z ≦ K
	 * @result X + Y + Z = S
	 */
	public static void main(String... args) {
		try (Scanner sc = new Scanner(System.in)) {
			int k = sc.nextInt();
			int s = sc.nextInt();
			int count = 0;
			for (int i = 0; i <= k; i++) {
				for (int j = 0; j <= k; j++) {
					if (0 <= s - i - j && s - i - j <= k) {
						count ++;
					}
				}
			}
			System.out.println(count);
		}
	}
}
