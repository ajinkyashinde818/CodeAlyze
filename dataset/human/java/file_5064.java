import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int n = sc.nextInt();
		boolean reverse = false;
		StringBuilder sb = new StringBuilder(s);
		StringBuilder mae = new StringBuilder();
		for (int i = 0; i < n; i++) {
			int q = sc.nextInt();
			if(q == 1) {
				reverse = !reverse;
			} else {
				int q2 = sc.nextInt();
				if(reverse) q2 = q2%2+1;
				if(q2 == 1) {
					mae.append(sc.next());
				} else {
					sb.append(sc.next());
				}
			}
		}
		mae.reverse();
		mae.append(sb);
		if(reverse) mae.reverse();
		System.out.println(mae.toString());
	}
}
