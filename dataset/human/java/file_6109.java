public class Main {
	public static void main(String[] args) {
		java.util.Scanner s = new java.util.Scanner(System.in);

		System.out.println((Main.calc(s.nextInt(), s.nextInt())));
	}

	public static int calc(int k, int s) {
		int count = 0;
		for (int x = 0; x <= k; x++) {
			for (int y = 0; y <= k; y++) {
				int z = s - x - y;
				if (0 <= z && z <= k) {
					count++;
				}
			}
		}
		return count;
	}
}
