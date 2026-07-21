import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int s = sc.nextInt();
		String ans = "";
		StringBuilder sb = new StringBuilder(ans);
		for(int i = 0 ; i < n ; i++) {
			if(i < k)
				sb.append(" " + s);
			else {
				if(s < 1000000000) {
					sb.append(" " + (s + 1));
				}
				else {
					sb.append(" " + 121313);
					}
			}
		}

		sc.close();
		System.out.println(sb.toString());

	}
}
