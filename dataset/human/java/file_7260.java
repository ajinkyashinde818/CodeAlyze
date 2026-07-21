import java.io.IOException;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);
		int k =  Integer.parseInt(sc.next());
		int n =  Integer.parseInt(sc.next());
		int[] A  = new int[n];
		
		int m = 0;
		for(int i = 0 ; i < n ; i++ ) {
			A[i] =  Integer.parseInt(sc.next());
		}
		
		for(int i = 0 ; i < n -1 ; i++ ) {
			m = Math.max(m, A[i+1] - A[i]);
		}
		
		m = Math.max(m, (k - A[n-1]) + A[0]);
		
		System.out.println(k - m);
		
		
		}
}
