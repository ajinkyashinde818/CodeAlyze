import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int K = in.nextInt();
      	int N = in.nextInt();
       	int[] A = new int[N];
       	int max = 0;
       	int remainder = 0;
       	int actualMax = 0;
       	
       	for(int i = 0; i<N; i++) {
       		A[i] = in.nextInt();
       		if (i > 0) {
           		max = Math.max(A[i]-A[i-1], max);
       		}
       	}
   		remainder = K-A[N-1]+A[0];
       	actualMax = Math.max(max, remainder);
       	
       	System.out.println(K-actualMax);
       	
	}
}
