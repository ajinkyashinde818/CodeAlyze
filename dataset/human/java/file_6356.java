import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt(), s = sc.nextInt(), ret = 0;
			for (int x = 0; x <= k; x++) {
				for (int y = 0; y <= k; y++) {
					if (s - x - y <= k && s - x - y >= 0) ret++;
				}
			}
		System.out.println(ret);
		sc.close();
	}
}
