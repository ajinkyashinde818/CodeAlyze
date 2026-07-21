import java.util.Scanner;
 
class Main {
 
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r = sc.nextInt();
 
		if (n >= 10) {
			int ans = r;
			System.out.println(ans);
		} else {
			int ans = r + (100 * (10 - n));
			System.out.println(ans);
		}
 
		sc.close();
	}
 
}
