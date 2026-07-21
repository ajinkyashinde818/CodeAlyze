import java.util.Scanner;
public class Main {
	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		
		int count = 0;
		int p = Math.max(a, b);
		for(int i = Math.min(a, b); i > 0; i--) {
			if(a % i == 0 && b % i == 0) {
				count++;
			    p = Math.min(i, p);
			}
			if(count == k)
				break;
		}
		
		System.out.println(p);

	}

}
