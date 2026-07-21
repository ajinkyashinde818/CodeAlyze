import java.util.Scanner;

public class Main {

	public static void main(final String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		boolean ret = false;
		int zorome = 0;
		for (int i = 0; i < n; i++) {
			int d1 = sc.nextInt();
			int d2 = sc.nextInt();
			if(d1 == d2) zorome++;
			else zorome = 0;
			if(zorome >= 3) ret = true;
		}
		sc.close();
		prtln(ret ? "Yes" : "No");
	}

	public static <T> void prtln(T t) { System.out.println(t); }
}
