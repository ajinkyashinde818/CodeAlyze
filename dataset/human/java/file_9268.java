import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static int N;
	public static int[] stair;
	public static long[] count;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		int M = sc.nextInt();
		List<Integer> broken = new ArrayList<>();
		boolean impossible = false;
		int tmp = -1;
		stair = new int[N + 1];
		count = new long[N + 1];
		for(int i = 0; i < N + 1; i++) {
			stair[i] = 0;
		}
		for(int i = 1; i < M + 1; i++) {
			int tmp2 = sc.nextInt();
			if(tmp + 1 == tmp2) {
				impossible = true;
				break;
			} else {
				stair[tmp2] = 1;
				tmp = tmp2;
			}
		}
		if(!impossible) {
			for(int i = 0; i < N + 1; i++) {
				count[i] = 0;
			}
			count[N] = 1;
			for(int i = N; i > 0; i--) {
				if(i > 1) {
					if(stair[i - 1] == 0) {
						count[i - 1] += count[i] % 1000000007;
					}
					if(stair[i - 2] == 0) {
						count[i - 2] += count[i] % 1000000007;
					}
				} else if(i == 1) {
					count[0] += count[i] % 1000000007;
				}
			}
			System.out.println(count[0] % 1000000007);
		} else {
			System.out.println(0);
		}
	}
}
