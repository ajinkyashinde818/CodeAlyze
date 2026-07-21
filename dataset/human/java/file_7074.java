import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);

		int k = sc.nextInt();
		int N = sc.nextInt();
		int A[] = new int[N];
		
		for(int i=0; i<N; i++) {
			A[i] = sc.nextInt();
		}
		
		int X = 0;
		int Y = A[0]+(k-A[N-1]);
		for(int i=0; i<N-1; i++) {
			X = A[i+1]-A[i];
		if(X>=Y) {
			Y = X;
		}	
		}
		System.out.print(k-Y);
	}
}
