import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int s = sc.nextInt();
		sc.close();
		
		
		int numOfs = 0;
		
		for(int i = 0; i < n; i ++) {
			if(numOfs != k) {
				System.out.print(s);
				numOfs++;
			}else {
				
				if(s == 1000000000) {
					System.out.print(s-1);
				}else {
					System.out.print(s+1);
				}
			}
			if(i != n - 1) {
				System.out.print(" ");
			}
			System.out.flush();
		}
		System.out.print("\n");
		System.out.flush();
	}
}
