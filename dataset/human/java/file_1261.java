import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		long[] A = new long[N];
		for(int i = 0 ; i < N ; i++){
			A[i] = sc.nextLong();
		}

		sc.close();

		long[] B = new long[N];
		B[0] = A[0];
		for(int i = 1 ; i < N ; i++){
			B[i] = B[i-1] + A[i];
		}

		long snk = 0;
		long arg = 0;
		long ans =0;
		for(int i = 0 ; i < N-1 ; i++){
			snk = B[i];
			arg = B[N-1]-B[i];

			if(i==0){
				ans = Math.abs(snk-arg);
			}
			else{
				ans = Math.min(ans, Math.abs(snk-arg));
			}
		}
		System.out.println(ans);


	}

}
