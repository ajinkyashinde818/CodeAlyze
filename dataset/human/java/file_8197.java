import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		long a = sc.nextInt();
		long b = sc.nextInt();
		long answer = 0;
		if(a > b) {
			answer = getMinimumValue(a,b);
		}else {
			answer = getMinimumValue(b,a);
		}
		System.out.println(answer);
	}

	private static long getMinimumValue(long big, long small) {
		long answer = small;
		long counter = 1;
		while(true) {
			answer = small * counter;
			if(answer % big ==0) {
				break;
			}
			counter++;
		}
		return answer;
	}
}
