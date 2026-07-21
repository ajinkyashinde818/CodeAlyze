import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int s = sc.nextInt();
		int max = 1000000000;
		for (int i = 0; i < n; i++) {
			if(i < k) {
				System.out.printf("%d ", s);
			}else {
				System.out.printf("%d ",s == max? max-1:s+1);
			}
		}
		sc.close();
	}
}
