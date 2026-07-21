import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		boolean exist = false;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int d1 = sc.nextInt();
			int d2 = sc.nextInt();
			
			if (d1 == d2) cnt++;
			else cnt = 0;
			
			if (cnt >= 3) {
				exist = true;
				break;
			}
		}
		
		System.out.println(exist ? "Yes" : "No");
		
		sc.close();
	}
}
