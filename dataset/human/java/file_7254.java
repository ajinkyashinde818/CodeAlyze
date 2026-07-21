import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] array = new int[n+1];
		int max_dis = -1;

		for(int i = 0; i < n; i++) {
			array[i] = sc.nextInt();
		}
		array[n] = k+array[0];

		for(int i = 1; i < n+1; i++) {
			int temp = array[i]-array[i-1];
			if(temp > max_dis) {
				max_dis = temp;
			}
		}
		System.out.println(k-max_dis);
	}
}
