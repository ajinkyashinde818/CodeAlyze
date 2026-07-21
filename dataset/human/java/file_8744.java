import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt();
		int k = sc.nextInt();
		for (int i = Math.min(a, b); i >= 1; i--) {
			if(a%i==0&&b%i==0) {
				if(k==1) {
					System.out.println(i);
					break;
				}else {
					k--;
				}
			}
		}
		sc.close();
	}
}
