import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long min = (long) Math.pow(10, 9);
		boolean minus = false;
		boolean zero = false;
		long ans = 0;
		for(int i = 0; i < N; i++) {
			long tmp = sc.nextLong();
			ans += Math.abs(tmp);
			min = Math.min(min, Math.abs(tmp));
			if(tmp < 0) {
				minus = !minus;
			} else if(tmp == 0) {
				zero = true;
			}
		}
		if((!zero) && minus) {
			ans -= min * 2;
		}
		System.out.println(ans);
	}

}
