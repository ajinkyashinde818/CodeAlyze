import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int number = sc.nextInt();
		int[] n = new int[number];
		int[] m = new int[number];

		for (int i = 0; i < number; i++) {
			n[i] = sc.nextInt();
			m[i] = sc.nextInt();
		}
		int cnt = 0;
		for (int i = 0; i < number; i++) {
			if (n[i] == m[i]) {
				cnt++;
			}else if(n[i] != m[i]) {
				cnt = 0;
			}
			if (cnt == 3) {
				System.out.println("Yes");
				return;
			}

		}
		
			System.out.println("No");
		

	}
}
