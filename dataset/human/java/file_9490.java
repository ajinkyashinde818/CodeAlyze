import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		int k = 0;
		for ( int i=0; i<n; i++ ) {
			int d1 = sc.nextInt();
			int d2 = sc.nextInt();

			if ( d1==d2 ) {
				k++;
				if ( k>=3 ) {
					System.out.println("Yes");
					System.exit(0);
				}
			} else {
				k = 0;
			}
		}

		System.out.println("No");
	}
}
