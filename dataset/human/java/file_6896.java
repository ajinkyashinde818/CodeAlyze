import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int k = scan.nextInt();
		int n = scan.nextInt();
		int count = 0;

		ArrayList<Integer> list = new ArrayList<Integer>(n);

		for(int i = 0;i < n;i++) {
			list.add(scan.nextInt());
		}

		for(int i = 1;i <= n;i++) {
			if(i == n) {
				if((k - list.get(n - 1)) + list.get(0) > count) {
					count = (k - list.get(n - 1)) + list.get(0);
				}
			}else {
				if((list.get(i) - list.get(i - 1)) > count) {
					count = list.get(i) - list.get(i - 1);
				}
			}
		}

		System.out.println(k - count);
	}
}
