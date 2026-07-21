import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private Scanner sc;

	public static void main(String[] args) {
		new Main();
	}
	
	public Main() {
		sc = new Scanner(System.in);

		int[] seats = {4, 1, 4, 1, 2, 1, 2, 1};
		
		while (sc.hasNextLine()) {
			String[] nico = sc.nextLine().split(" ");
			
			int[] guests = new int[nico.length];
			for (int i = 0; i < nico.length; i++) {
				guests[i] = Integer.parseInt(nico[i]);
			}
			
			int[] sum = new int[seats.length];
			for (int i = 0; i < sum.length; i++) {
				sum[i] = 0;
			}
			
			int max = 0;
			for (int j = 0; j < seats.length; j++) {
				sum[j] = 0;
				for (int i = 0; i < seats.length; i++) {
					int index = (i + j) % seats.length;
					sum[j] = sum[j] + Math.min(seats[index], guests[i]);
				}
				
				if (max < sum[j]) max = sum[j];
			}

			int[] ans = new int[sum.length];
			for (int i = 0; i < ans.length; i++) {
				ans[i] = 0;
			}
			
			for (int i = 0; i < sum.length; i++) {
				if (sum[i] == max) {
					for (int j = 0; j < seats.length; j++) {
						int index = (i + j) % seats.length;
						ans[i] = ans[i] * 10 + seats[index];
					}
				}
			}
			Arrays.sort(ans);
			
			String s = "";
			for (int i = 0; i < ans.length; i++) {
				if (ans[i] != 0) {
					s = s + (ans[i] % 10);
					for (int j = 1; j < seats.length; j++) {
						ans[i] = ans[i] / 10;
						s = (ans[i] % 10) + " " + s;
					}
					break;
				}
			}
			
			System.out.println(s);
		}
	}
}
