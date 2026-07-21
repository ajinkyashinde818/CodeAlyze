import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		ArrayList<Integer> list = new ArrayList<>();
		long N = scan.nextLong();
		double R = Math.sqrt(N);
		int num = 0;
		int ans = 0;

		if(N == 1) {

			System.out.println(0);

		} else {

			for (int i = 2; i <= R; i++) {
				num = power(N, i);
				list.add(num);
				for (int j = 0; j < num; j++) {
					N /= i;
				}
			}
			if (N != 1) {
				ans++;
			}
			for (int i = 0; i < list.size(); i++) {
				ans += times(list.get(i));
			}

			System.out.println(ans);
		}
	}

	public static int power(long N, int i){
		int num = 0;
		while (N % i == 0) {
				N /= i;
				num++;
		}
		return num;
	}

	public static int times(int a) {
		int b = 0;
		if (a == 0) {

		} else if (a < 3) {
			b = 1;
		} else if (a < 6){
			b = 2;
		} else if (a < 10){
			b = 3;
		} else if (a < 15){
			b = 4;
		} else if (a < 21){
			b = 5;
		} else if (a < 28){
			b = 6;
		} else if (a < 36){
			b = 7;
		} else {
			b = 8;
		}
		return b;
	}

}
