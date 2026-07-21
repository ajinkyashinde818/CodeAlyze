import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		var sc = new Scanner(System.in);
		var n = sc.nextInt();
		var d1 = new int[n];
		var d2 = new int[n];
		for (var i = 0; i<n; i++) {
			d1[i] = sc.nextInt();
			d2[i] = sc.nextInt();
		}
		sc.close();

		var count = 0;
		var result = false;
		for (var i = 0; i<n; i++) {
			if (d1[i] == d2[i]) {
				count++;
				if (count >= 3) {
					result = true;
				}
			} else {
				count = 0;
			}
		}
		System.out.println(result ? "Yes" : "No");
	}
}
