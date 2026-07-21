import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i=0; i<N; i++)
			A[i] = sc.nextInt();
	
		System.out.println(check(A) ? "YES" : "NO");
		sc.close();
	}
	
	static boolean check(int[] A) {
		int N = A.length;
		long sum = 0;
		for(int i=0; i<N; i++)
			sum += A[i];
		
		if(sum%((long)N*(N+1)/2)!=0)
			return false;
		
		int op = (int)(sum/((long)N*(N+1)/2));
		
		for(int i=0; i<N; i++) {
			int diff = A[(i+1)%N]-A[i];
			if((diff>op))
				return false;
			if((op-diff)%N!=0)
				return false;
		}
		
		return true;
	}
}
