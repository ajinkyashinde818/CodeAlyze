import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] input = new int[N];
		for (int i = 0; i < input.length; i++) {
			input[i] = sc.nextInt();
		}
		int[] diff = new int[N];
		for (int i = 0; i < input.length - 1; i++) {
			diff[i] = input[i + 1] - input[i];
		}
		diff[N - 1] = K - input[N - 1] + input[0];
		Arrays.sort(diff);
		long res = 0;
		for (int i = 0; i < input.length - 1; i++) {
			res += diff[i];
		}
		System.out.println(res);

	}
}
