import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int s = sc.nextInt();
		int count = 0;
		for (int i = 0; i <= k; i++) {
			for (int t = 0; t <= k; t++) {
				int z = s - i - t;
				if(0 <= z && z <= k) {
					count++;
				}
			}
		}
		System.out.println(count);
	}
}
