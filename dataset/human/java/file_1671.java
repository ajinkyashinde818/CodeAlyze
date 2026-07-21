import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		sc.nextInt();
		String s = sc.next();

		long[] m = new long[26];

		for (char c : s.toCharArray())
			m[c - 'a']++;

		long ans = 1;
		for (int i = 0; i < m.length; i++) {
			ans = ans * (m[i] + 1) % 1_000_000_007;
		}

		ans--;

		System.out.println(ans);

		sc.close();
	}

}
