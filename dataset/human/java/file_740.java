import java.util.Scanner;

public class Main {

	public static int N;
	public static int R;

	public static void main(String[] args) {
		init();
		if (N >= 10) {
			System.out.println(R);
		} else {
			System.out.println((R + 100 * (10 - N)));
		}

	}

	public static void init() {
		Scanner sc = new Scanner(System.in);
		try {
			N = sc.nextInt();
			R = sc.nextInt();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
