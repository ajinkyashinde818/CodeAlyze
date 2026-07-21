import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		int N= scan.nextInt();
		int[][] darr = new int[N][2];
		int zorome = 0;
		for (int i = 0; i < N; i++) {
			darr[i][0] = Integer.parseInt(scan.next());
			darr[i][1] = Integer.parseInt(scan.next());
			if (darr[i][0]==darr[i][1]) {
				zorome++;
				if (zorome ==3) {
					System.out.println("Yes");
					return;
				}
			} else {
				zorome = 0;
			}
		}
		System.out.println("No");
		return;
	}

}
