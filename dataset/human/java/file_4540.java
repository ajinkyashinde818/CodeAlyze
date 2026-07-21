import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
		sc.close();

		long cnt = 0;
		if(c >= 1) {
			cnt ++;
			c -= 1;
		}

		if(b >= c) {
			cnt += b + c;
		}else if(b < c) {
			cnt += b*2;
			c -= b;
			if(a >= 1) {
				if(a >= c) {
					cnt += c;
				}else if(a < c) {
					cnt += a;
				}
			}
		}
		System.out.println(cnt);
	}

}
