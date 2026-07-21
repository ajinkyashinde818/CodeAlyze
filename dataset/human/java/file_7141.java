import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = Integer.parseInt(sc.next());
		int n = Integer.parseInt(sc.next());

		int[] house = new int[n];
		for (int i = 0; i < n; i++) {
			house[i] = Integer.parseInt(sc.next());
		}
		int[] area = new int[n];
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				area[i] =  house[0]+k-house[i];
			} else {
				area[i] = house[i + 1] - house[i];
			}
		}
		Arrays.sort(area);
		int length = 0;
		for (int i = 0; i < n - 1; i++) {
			length += area[i];
		}
		System.out.println(length);

	}

}
