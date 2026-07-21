import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int k = sc.nextInt();
		int s = sc.nextInt();
		int a, b, c ;
		int count = 0;
		for( a = 0; a <= k ;a++) {
			for( b = 0; b <= k ; b++) {
				c = s - a - b;
				if(c >= 0 && c <= k) count++;
			 }
			}
		System.out.println(count);
		}
		

	}
