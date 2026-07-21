import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), r = sc.nextInt();
		int ans = (n >= 10 ? r : r + (100 * (10 - n)));
		sc.close();
		System.out.println(ans);
	}
}
