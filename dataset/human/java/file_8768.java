import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int gcd = gcd(a,b);
		int cnt = 0;
		int ans = 0;
			for(int i = gcd; i >= 1; i--) {
				if(a%i == 0 && b%i == 0) {
					ans = i;
					cnt ++;
					if(cnt == c) {
						System.out.println(ans);
					}
				}
				
			}
		
		sc.close();
	}
	static int gcd (int a, int b) {
		int temp;
		while((temp = a%b)!=0) {
			a = b;
			b = temp;
		}
		return b;
	}
}
