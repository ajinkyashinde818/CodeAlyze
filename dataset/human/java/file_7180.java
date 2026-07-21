import java.util.Scanner;

public class Main {

	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		int n = scan.nextInt();
		int[] A = new int[n];
		for(int i=0; i<n; i++)A[i]=scan.nextInt();
		int r = k -(A[0]+(k-A[n-1]));
		int l = k-(A[1]-A[0]);
		int min = Math.min(r, l);
		for(int i=1; i<n-1; i++) {
			l = k-(A[i+1]-A[i]);
			min = Math.min(min, l);
		}
		System.out.println(min);
	}

}
