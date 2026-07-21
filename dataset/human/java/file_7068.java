import java.util.*; 
import java.lang.*; 

public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		
		long K = scan.nextInt();
		int N = scan.nextInt();
			
		long[] A = new long[N];
		long[] P = new long[N+1];
		
		long Ans = 0;
		
		for(int i=0; i<N;i++){
			A[i] = scan.nextInt();
		}
		
		for(int i=1; i<N;i++){
			P[i-1] = A[i] -A[i-1];
		}
		
		P[N-1] = K - A[N-1] + A[0];
		
		long max = 0;
		
		for(int i=0; i<=N;i++){
			if(max<=P[i]){
				max = P[i];
			}
		}
		
		for(int i=0; i<=N;i++){
			Ans = Ans + P[i];
		}
		
		Ans = Ans - max;
			
		System.out.println(Ans);
	}
}
