import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
	    Scanner scanner = new Scanner(System.in);

	    int K = Integer.parseInt(scanner.next());
	    int N = Integer.parseInt(scanner.next());
	    int A[] = new int[N];
	    
	    for (int i=0; i<N; i++) {
	    	A[i] = Integer.parseInt(scanner.next());
	    }
	    
	    int max = K - (A[N-1] - A[0]);
	    for (int i=0; i<N-1; i++) {
	        if (max < A[i+1] - A[i]) max=A[i+1] - A[i];
	    }
        System.out.print(K-max);
	}

}
