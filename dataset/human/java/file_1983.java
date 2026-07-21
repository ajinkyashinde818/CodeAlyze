import java.util.Scanner;


public class Main {
	private static int n;
	private static int K;
	private static int[] A;
	private static long[] B;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		K = in.nextInt();
		
		A = new int[n];
		B = new long[n];
		long rs = 0;
		for(int i=0;i<n;i++){
			A[i] = in.nextInt();
			B[i] = in.nextLong();
			
			if((K&A[i])==A[i]){
				rs = rs + B[i];
			}
		}
		
		for(int i=30;i>=0;i--){
			int tmp = 1<<i;
			
			if( (K&tmp) == tmp ){
				
				int x = (K^tmp)|(tmp-1);
				long ans  = 0;
				
				for(int j=0;j<n;j++){
					if( (x&A[j]) == A[j]){
						ans = ans + B[j];
					}
				}
				rs = ans>rs?ans:rs;
			}
		}
		System.out.println(rs);
		
	}
}
